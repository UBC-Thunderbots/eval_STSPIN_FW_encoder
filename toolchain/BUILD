load("@rules_cc//cc:defs.bzl", "cc_toolchain")
load("@bazel_tools//tools/cpp:unix_cc_toolchain_config.bzl", "cc_toolchain_config")

filegroup(
    name = "empty",
    srcs = [],
)

filegroup(
    name = "arm_none_eabi_files",
    srcs = [],
)

cc_toolchain_config(
    name = "arm_none_eabi_config",
    cpu = "arm",
    compiler = "gcc",
    toolchain_identifier = "arm-none-eabi",
    host_system_name = "local",
    target_system_name = "arm-none-eabi",
    target_libc = "none",
    abi_version = "eabi",
    abi_libc_version = "none",
    tool_paths = {
        "gcc": "arm-none-eabi-gcc",
        "ar": "arm-none-eabi-ar",
        "ld": "arm-none-eabi-ld",
        "cpp": "arm-none-eabi-cpp",
        "gcov": "arm-none-eabi-gcov",
        "nm": "arm-none-eabi-nm",
        "objdump": "arm-none-eabi-objdump",
        "strip": "arm-none-eabi-strip",
    },
    compile_flags = [
        "-mcpu=cortex-m4",
        "-mthumb",
        "-mfloat-abi=hard",
        "-mfpu=fpv4-sp-d16",
        "-ffunction-sections",
        "-fdata-sections",
        "-fno-exceptions",
        "-fno-rtti",
    ],
    link_flags = [
        "-mcpu=cortex-m4",
        "-mthumb",
        "-mfloat-abi=hard",
        "-mfpu=fpv4-sp-d16",
        "-specs=nano.specs",
        "-Wl,--gc-sections",
    ],
    cxx_flags = [
        "-fno-exceptions",
        "-fno-rtti",
    ],
)

cc_toolchain(
    name = "arm_none_eabi_toolchain",
    toolchain_identifier = "arm-none-eabi-toolchain",
    toolchain_config = ":arm_none_eabi_config",
    all_files = ":arm_none_eabi_files",
    ar_files = ":arm_none_eabi_files",
    compiler_files = ":arm_none_eabi_files",
    dwp_files = ":empty",
    linker_files = ":arm_none_eabi_files",
    objcopy_files = ":empty",
    strip_files = ":empty",
    supports_param_files = 0,
)

toolchain(
    name = "arm_none_eabi_toolchain_definition",
    exec_compatible_with = [
        "@platforms//cpu:x86_64",
        "@platforms//os:linux",
    ],
    target_compatible_with = [
        "@platforms//cpu:arm",
        "@platforms//os:none",
    ],
    toolchain = ":arm_none_eabi_toolchain",
    toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
)

