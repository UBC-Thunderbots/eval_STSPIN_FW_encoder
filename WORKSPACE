workspace(name = "mdfw_workspace")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "rules_cc",
    remote = "https://github.com/bazelbuild/rules_cc",
    branch = "main",
)

git_repository(
    name = "arm_none_eabi",
    remote = "https://github.com/hexdae/toolchains_arm_gnu",
    branch = "master",
)

load("@toolchains_arm_gnu//:deps.bzl", "arm_none_eabi_deps")
arm_none_eabi_deps()
register_toolchains("@arm_none_eabi//toolchain:all")

load("@toolchains_arm_gnu//:deps.bzl", "arm_none_linux_gnueabihf_deps")
arm_none_linux_gnueabihf_deps()
register_toolchains("@arm_none_linux_gnueabihf//toolchain:all")

load("@toolchains_arm_gnu//:deps.bzl", "aarch64_none_elf_deps")
aarch64_none_elf_deps()
register_toolchains("@aarch64_none_elf//toolchain:all")

load("@toolchains_arm_gnu//:deps.bzl", "aarch64_none_linux_gnu_deps")
aarch64_none_linux_gnu_deps()
register_toolchains("@aarch64_none_linux_gnu//toolchain:all")

register_toolchains(
    "//toolchain:arm_none_eabi_toolchain_definition",
)

