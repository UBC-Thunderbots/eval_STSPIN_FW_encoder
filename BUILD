cc_binary(
    name = "mdfw",
    srcs = glob(
        [
            "Src/**/*.c",
            "Drivers/STM32F0xx_HAL_Driver/Src/*.c",
            "MCSDK_v6.2.0-Full/**/*.c",
        ]
    ),
    copts = [
        "-I./Inc/maxon_ec_45",
        "-I./Drivers/STM32F0xx_HAL_Driver/Inc",
        "-I./Drivers/STM32F0xx_HAL_Driver/Inc/Legacy",
        "-I./MCSDK_v6.2.0-Full/MotorControl/MCSDK/MCLib/Any/Inc",
        "-I./Drivers/CMSIS/Device/ST/STM32F0xx/Include",
        "-I./Drivers/CMSIS/Include",
        "-I./Drivers/CMSIS/DSP/Include",
    ],
    linkopts = ["-TSTM32F031C6TX_FLASH.ld"],
)
