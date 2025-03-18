load("@rules_cc//cc:defs.bzl", "cc_library")

INCLUDE_DIRECTORIES = [
        "Inc/maxon_ec_45",
        "Drivers/STM32F0xx_HAL_Driver/Inc",
        "Drivers/STM32F0xx_HAL_Driver/Inc/Legacy",
        "MCSDK_v6.2.0-Full/MotorControl/MCSDK/MCLib/Any/Inc",
        "Drivers/CMSIS/Device/ST/STM32F0xx/Include",
        "Drivers/CMSIS/Include",
        "Drivers/CMSIS/DSP/Include",
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
    features = ["-cpp"],
    copts = [
        "-std=gnu11",
        "-nostdlib",
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
        "-Wall"
    ],
    linkopts = [
        "-TSTM32F031C6TX_FLASH.ld",
        "-mcpu=cortex-m0",
        "-mthumb",
        "-nostdlib",
        "-mfloat-abi=soft",
        "-specs=nosys.specs",
        "-Wl,--gc-sections",
        "-Wl,-Map=motor_driver_eval_graph.map"
    ],
)

cc_library(
    name = "STM32F0_HAL_Driver",
    srcs = glob([
        "Drivers/STM32F0xx_HAL_Driver/**/*.c"
    ]),
    hdrs = glob(["**/*.h"]),
    defines = [],
    includes = [],
)
