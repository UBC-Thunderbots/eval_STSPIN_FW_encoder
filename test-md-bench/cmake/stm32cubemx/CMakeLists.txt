cmake_minimum_required(VERSION 3.22)

project(stm32cubemx)
add_library(stm32cubemx INTERFACE)

# Enable CMake support for ASM and C languages
enable_language(C ASM)

target_compile_definitions(stm32cubemx INTERFACE 
	ARM_MATH_CM0 
	USE_HAL_DRIVER 
	STM32F031x6
    $<$<CONFIG:Debug>:DEBUG>
)

target_include_directories(stm32cubemx INTERFACE
    ../../Inc
    ../../Drivers/STM32F0xx_HAL_Driver/Inc
    ../../Drivers/STM32F0xx_HAL_Driver/Inc/Legacy
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Inc
    ../../Drivers/CMSIS/Device/ST/STM32F0xx/Include
    ../../Drivers/CMSIS/Include
    ../../Drivers/CMSIS/DSP/Include
)

target_sources(stm32cubemx INTERFACE
    ../../Src/main.c
    ../../Src/motorcontrol.c
    ../../Src/pwm_common.c
    ../../Src/mc_api.c
    ../../Src/mc_config.c
    ../../Src/mc_config_common.c
    ../../Src/mcp_config.c
    ../../Src/mc_tasks.c
    ../../Src/mc_tasks_foc.c
    ../../Src/pwm_curr_fdbk.c
    ../../Src/regular_conversion_manager.c
    ../../Src/mc_math.c
    ../../Src/mc_interface.c
    ../../Src/stm32_mc_common_it.c
    ../../Src/stm32f0xx_mc_it.c
    ../../Src/mc_parameters.c
    ../../Src/register_interface.c
    ../../Src/mcp.c
    ../../Src/r1_ps_pwm_curr_fdbk.c
    ../../Src/usart_aspep_driver.c
    ../../Src/mc_configuration_registers.c
    ../../Src/aspep.c
    ../../Src/mc_app_hooks.c
    ../../Src/stm32f0xx_it.c
    ../../Src/stm32f0xx_hal_msp.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_adc_ex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_rcc_ex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_i2c_ex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_gpio.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_dma.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_cortex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_pwr_ex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_flash_ex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_exti.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_tim_ex.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart.c
    ../../Drivers/STM32F0xx_HAL_Driver/Src/stm32f0xx_hal_uart_ex.c
    ../../Src/system_stm32f0xx.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/bus_voltage_sensor.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/circle_limitation.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/digital_output.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/enc_align_ctrl.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/encoder_speed_pos_fdbk.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/ntc_temperature_sensor.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/open_loop.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/pid_regulator.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/pqd_motor_power_measurement.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/r_divider_bus_voltage_sensor.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/ramp_ext_mngr.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/revup_ctrl.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/speed_pos_fdbk.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/speed_torq_ctrl.c
    ../../MCSDK_v6.3.1-Full/MotorControl/MCSDK/MCLib/Any/Src/virtual_speed_sensor.c
    ../../Src/sysmem.c
    ../../Src/syscalls.c
    ../../startup_stm32f031x6.s
)

target_link_directories(stm32cubemx INTERFACE
)

target_link_libraries(stm32cubemx INTERFACE
)

# Validate that STM32CubeMX code is compatible with C standard
if(CMAKE_C_STANDARD LESS 11)
    message(ERROR "Generated code requires C11 or higher")
endif()


