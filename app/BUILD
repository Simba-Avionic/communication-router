cc_binary(
    name = "router",
    srcs = [
        "main.cc",
        "router.cc",
        "router.h",
    ],
    data = ["//app/resource:json_files"],
    deps = [
        "//app/json-parser:JsonParser",
        "@com_json//:json",
        "@core",
    ],
)
