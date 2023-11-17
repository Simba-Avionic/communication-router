workspace(name="router")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
local_repository(
    name = "core",
    path = "core",
)

load("@core//bazel:third_party_repositories.bzl", "include_spdlog")
include_spdlog()

local_repository(
    name = "communication_core",
    path = "communication-core",
)

http_archive(
    name = "com_google_benchmark",
    sha256 = "bdefa4b03c32d1a27bd50e37ca466d8127c1688d834800c38f3c587a396188ee",
    strip_prefix = "benchmark-1.5.3",
    urls = ["https://github.com/google/benchmark/archive/v1.5.3.zip"],
)

http_archive(
    name = "com_google_googletest",
    strip_prefix = "googletest-5ab508a01f9eb089207ee87fd547d290da39d015",
    urls = ["https://github.com/google/googletest/archive/5ab508a01f9eb089207ee87fd547d290da39d015.zip"],
)