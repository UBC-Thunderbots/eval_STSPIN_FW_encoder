load("@rules_cc//cc:defs.bzl", "cc_library")
load("@hedron_compile_commands//:refresh_compile_commands.bzl", "refresh_compile_commands")

INCLUDE_DIRECTORIES = [
    "Inc/maxon_ec_45",
    "Drivers/STM32F0xx_HAL_Driver/Inc",
    "Drivers/STM32F0xx_HAL_Driver/Inc/Legacy",
    "MCSDK_v6.2.0-Full/MotorControl/MCSDK/MCLib/Any/Inc",
    "Drivers/CMSIS/Device/ST/STM32F0xx/Include",
    "Drivers/CMSIS/Include",
    "Drivers/CMSIS/DSP/Include",
]

COPTS = [
    "-std=gnu11",
    "-DARM_MATH_CM0",
    "-DUSE_HAL_DRIVER",
    "-DSTM32F031x6",
    "-DDEBUG",
    "-fstack-usage",
    "-mthumb",
    "-mfloat-abi=soft",
    "-ffunction-sections",
    "-fdata-sections",
    "-fno-exceptions",
    "-Wall",
    "-Ofast"
]

cc_binary(
    name = "mdfw",
    srcs = glob(
        [
            "Src/**/*.c",
            "Drivers/STM32F0xx_HAL_Driver/Src/*.c",
            "MCSDK_v6.2.0-Full/**/*.c",
        ]
    ),
    includes = INCLUDE_DIRECTORIES,
    copts = COPTS,
    linkopts = [
        "-TSTM32F031C6TX_FLASH.ld",
        "-mcpu=cortex-m0",
        "-mthumb",
        "-mfloat-abi=soft",
        "-specs=nosys.specs",
        "-Wl,--gc-sections",
        "-Wl,-Map=motor_driver_eval_graph.map"
    ],
)

cc_library(
    name = "HAL_Driver",
    srcs = glob([
        "Drivers/STM32F0xx_HAL_Driver/**/stm32f0xx_hal*.c"
    ]),
    defines = [],
    copts = ["-include stdint.h"] + COPTS,
    includes = INCLUDE_DIRECTORIES,
    alwayslink = True,
)

cc_library(
    name = "CMSIS",
    srcs = glob([
        "Drivers/CMSIS/system_*.c"
    ]),
    hdrs = glob([
        "Drivers/**/*.h",
        "Inc/**/*.h",
    ]),
    defines = [],
    copts = ["-include stdint.h"] + COPTS,
    includes = INCLUDE_DIRECTORIES,
    alwayslink = True,
    target_compatible_with = ["@platforms//cpu:armv6-m"]
)

cc_library(
    name = "MotorControl",
    srcs = glob([

    ])
)


refresh_compile_commands(
    name = "refresh_compile_commands",

    # Specify the targets of interest.
    # For example, specify a dict of targets and any flags required to build.
    targets = ["//:STM32F0_HAL_Driver"]
    # No need to add flags already in .bazelrc. They're automatically picked up.
    # If you don't need flags, a list of targets is also okay, as is a single target string.
    # Wildcard patterns, like //... for everything, *are* allowed here, just like a build.
      # As are additional targets (+) and subtractions (-), like in bazel query https://docs.bazel.build/versions/main/query.html#expressions
    # And if you're working on a header-only library, specify a test or binary target that compiles it.
)
