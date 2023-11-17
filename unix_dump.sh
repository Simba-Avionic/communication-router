#!/bin/bash


which socat >/dev/null 2>&1
if $?; then
    echo "Please install socat using \"yum install socat -y\""
    exit 1
fi

which tshark >/dev/null 2>&1
if $?; then
    echo "Please install tshark using \"yum install wireshark -y\""
    exit 1
fi

_usage()
{
    echo -e "\nUsage: $0 \n\
        -u unix domain socket file name\n\
        -w capture file name, Default /tmp/unix_socket_dump_$(date +%s)_$(hostname).pcap\n\
        -h to display the usage\n"
    exit 1
}

_cleanup()
{
    if ps -p "$socatTcpListener" > /dev/null ;then
        kill -9 "$socatTcpListener"
    fi

    if ps -p "$socatUnixListener" > /dev/null ;then
        kill -9 "$socatUnixListener"
    fi

    if [ -f "$unixSocketFile" ]; then
        rm "${unixSocketFile}"
    fi
    mv "${source_socket}" "${unixSocketFile}"
}

unixSocketFile=
captureDumpFile="/tmp/unix_socket_dump_$(date +%s)_$(hostname).pcap"
sockatTimeoutInterval=100
wiresharkPort=9888

while getopts "hu:w" arg
do
    case $arg in
        u)
            unixSocketFile=${OPTARG}
            ;;
        w)
            captureDumpFile=${OPTARG}
            ;;
        h)
            _usage
            ;;
    esac
done

if [ -z "$unixSocketFile" ]; then
    _usage
fi

if [ ! -S "$unixSocketFile" ] ; then
    echo "Unix socket file not present, Make sure the server is running"
    exit 1
fi

echo "Capturing data from $unixSocketFile and dumping to $captureDumpFile"

source_socket="$(dirname "${unixSocketFile}")/$(basename "${unixSocketFile}").orig"

# Move socket files
mv "${unixSocketFile}" "${source_socket}"

trap "_cleanup" SIGINT

# Setup pipe over TCP that we can tap into
socat -t${sockatTimeoutInterval} "TCP-LISTEN:${wiresharkPort},reuseaddr,fork" "UNIX-CONNECT:${source_socket}" &
socatTcpListener=$!
socat -t${sockatTimeoutInterval} "UNIX-LISTEN:${unixSocketFile},mode=777,reuseaddr,fork" "TCP:localhost:${wiresharkPort}" &
socatUnixListener=$!

# Record traffic
tshark -i lo -w "${captureDumpFile}" -F pcapng "dst port ${wiresharkPort} or src port ${wiresharkPort}"