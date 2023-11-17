cc_binary(
    name = "router",
    srcs = [
        "main.cc",
        "router.cc",
        "router.h",
    ],
    data = ["//app/resource:json_files"],
    deps = [
        "//app/database:DatabaseLib",
        "//app/json-parser:JsonParser",
        "@com_json//:json",
        "@communication_core",
        "@core",
    ],
)

cc_binary(
    name = "router2",
    srcs = [
        "main.cc",
        "router2.cc",
        "router.h",
    ],
    data = ["//app/resource:json_files"],
    deps = [
        "//app/database:DatabaseLib",
        "//app/json-parser:JsonParser",
        "@com_json//:json",
        "@communication_core",
        "@core",
    ],
)
