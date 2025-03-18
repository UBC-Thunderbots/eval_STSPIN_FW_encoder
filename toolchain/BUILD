
load("@arm_none_eabi//toolchain:toolchain.bzl", "arm_none_eabi_toolchain")

arm_none_eabi_toolchain(
    name = "mdfw_toolchain",
    copts = [
        "-mcpu=cortex-m0",
        "-std=gnu11",
        "-DARM_MATH_CM0",
        "-DUSE_HAL_DRIVER",
        "-DSTM32F031x6",
        "-fstack-usage",
        "-mthumb",
        "-mfloat-abi=soft",
        "-ffunction-sections",
        "-fdata-sections",
        "-fno-exceptions",
        "-fno-rtti",
        "-Wall",
    ],
    linkopts = [
        "-mcpu=cortex-m0",
        "-mthumb",
        "-mfloat-abi=soft",
        "-specs=nosys.specs",
        "-Wl,--gc-sections",
        "-Wl,-Map=motor_driver_eval_graph.map",
        "-nostartfiles",
    ]
)



# load("@rules_cc//cc:defs.bzl", "cc_toolchain")
# load("@bazel_tools//tools/cpp:unix_cc_toolchain_config.bzl", "cc_toolchain_config")
#
# platform(
#     name = "motordriver_firmware",
#     constraint_values = [
#         "@platforms//cpu:armv6-m",
#         "@platforms//os:none",
#     ]
# )
#
# filegroup(name = "empty")
#
# filegroup(
#     name = "arm_none_eabi_files",
#     srcs = [],
# )
#
# cc_toolchain_config(
#     name = "arm_none_eabi_config",
#     cpu = "arm",
#     compiler = "arm-none-eabi-gcc",
#     toolchain_identifier = "arm-none-eabi",
#     host_system_name = "local",
#     target_system_name = "arm-none-eabi",
#     target_libc = "none",
#     abi_version = "eabi",
#     abi_libc_version = "none",
#     tool_paths = {
#         "gcc": "arm-none-eabi-gcc",
#         "ar": "arm-none-eabi-ar",
#         "ld": "arm-none-eabi-ld", # this should probably by -gcc but i'll figure this out later
#         "cpp": "arm-none-eabi-cpp",
#         "gcov": "arm-none-eabi-gcov",
#         "nm": "arm-none-eabi-nm",
#         "objdump": "arm-none-eabi-objdump",
#         "strip": "arm-none-eabi-strip",
#     },
#     compile_flags = [
#         "-mcpu=cortex-m0",
#         "-std=gnu11",
#         "-DARM_MATH_CM0",
#         "-DUSE_HAL_DRIVER",
#         "-DSTM32F031x6",
#         "-fstack-usage",
#         "-mthumb",
#         "-mfloat-abi=soft",
#         "-ffunction-sections",
#         "-fdata-sections",
#         "-fno-exceptions",
#         "-fno-rtti",
#         "-Wall",
#     ],
#     link_flags = [
#         "-mcpu=cortex-m0",
#         "-mthumb",
#         "-mfloat-abi=soft",
#         "-specs=nosys.specs",
#         "-Wl,--gc-sections",
#         "-Wl,-Map=motor_driver_eval_graph.map"
#     ],
#     cxx_flags = [
#         "-fno-exceptions",
#         "-fno-rtti",
#     ],
# )
#
# cc_toolchain(
#     name = "arm_none_eabi_toolchain",
#     toolchain_identifier = "arm-none-eabi-toolchain",
#     toolchain_config = ":arm_none_eabi_config",
#     all_files = ":arm_none_eabi_files",
#     ar_files = ":arm_none_eabi_files",
#     compiler_files = ":arm_none_eabi_files",
#     dwp_files = ":empty",
#     linker_files = ":arm_none_eabi_files",
#     objcopy_files = ":empty",
#     strip_files = ":empty",
#     supports_param_files = 0,
#     visibility = ["//visibility:public"]
# )
#
# toolchain(
#     name = "arm_none_eabi_toolchain_definition",
#     target_compatible_with = [
#         "@platforms//cpu:armv6-m",
#         "@platforms//os:none",
#     ],
#     toolchain = ":arm_none_eabi_toolchain",
#     toolchain_type = "@bazel_tools//tools/cpp:toolchain_type",
#     visibility = ["//visibility:public"],
# )
#
