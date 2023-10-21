load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name="communication_router",
    deps=[
        "@com_google_googletest//:gtest_main",
        "@com_google_benchmark//:benchmark_main",
    ]
)

cc_test(
    name = "com_router_test",
    srcs = ["test/sample_test.cc"],
    deps = ["@com_google_googletest//:gtest_main"],
)
#bazel run :benchmark
cc_binary(
    name = "com_router_benchmark",
    srcs = ["test/benchmark/sample_benchmark.cc"],
    deps = [
        "@com_google_benchmark//:benchmark_main",
    ],
)