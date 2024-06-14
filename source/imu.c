/******************************************************************************
* File Name:   imu.c
*
* Description: This file contains basic initialization code for dealing with
* the IMU sensor.
*
*******************************************************************************
* Copyright 2024, Cypress Semiconductor Corporation (an Infineon company) or
* an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
*
* This software, including source code, documentation and related
* materials ("Software") is owned by Cypress Semiconductor Corporation
* or one of its affiliates ("Cypress") and is protected by and subject to
* worldwide patent protection (United States and foreign),
* United States copyright laws and international treaty provisions.
* Therefore, you may use this Software only as provided in the license
* agreement accompanying the software package from which you
* obtained this Software ("EULA").
* If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
* non-transferable license to copy, modify, and compile the Software
* source code solely for use in connection with Cypress's
* integrated circuit products.  Any reproduction, modification, translation,
* compilation, or representation of this Software except as specified
* above is prohibited without the express written permission of Cypress.
*
* Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
* reserves the right to make changes to the Software without notice. Cypress
* does not assume any liability arising out of the application or use of the
* Software or any product or circuit described in the Software. Cypress does
* not authorize its products for use in any products where a malfunction or
* failure of the Cypress product may reasonably be expected to result in
* significant property damage, injury or death ("High Risk Product"). By
* including Cypress's product in a High Risk Product, the manufacturer
* of such system or application assumes all risk of such use and in doing
* so agrees to indemnify Cypress against all liability.
*******************************************************************************/

#include "utils.h"
#include "cybsp.h"
#if (IMU_INTERFACE_I2C == IMU_INTERFACE_SELECTED)
#include "cyhal_i2c.h"

#define IMU_I2C_FREQUENCY (1000000u)

static cyhal_i2c_t i2c_obj;

cyhal_i2c_t* get_i2c(void)
{
    return &i2c_obj;
}
#elif (IMU_INTERFACE_SPI == IMU_INTERFACE_SELECTED)
#include "cyhal_spi.h"
#include "cyhal_gpio.h"

#define IMU_SPI_FREQUENCY (10000000u)

static cyhal_spi_t spi_obj;

cyhal_spi_t* get_spi(void)
{
    return &spi_obj;
}
#else
#error "IMU_INTERFACE_SELECTED should be defined in sensor.h as either IMU_INTERFACE_I2C or IMU_INTERFACE_SPI."
#endif


#if defined(AI_KIT)
    static void update_sensor_ranges_bmi270(struct bmi2_dev* sensor)
    {
        struct bmi2_sens_config config = {0};
        /* Select the Output data rate, range of accelerometer sensor */
        config.type = BMI2_ACCEL;
        config.cfg.acc.range = BMI2_ACC_RANGE_8G;
        int8_t status = bmi2_set_sensor_config(&config, 1, sensor);
        config.type = BMI2_GYRO;
        config.cfg.gyr.range = BMI2_GYRO_FOC_500_DPS_REF;
        status = bmi2_set_sensor_config(&config, 1, sensor);
        if (BMI2_OK != status)
        {
            MTB_HALT("Error updating the IMU sensor configuration.\n");
        }
    }
#else
    static void update_sensor_ranges_bmi160(struct bmi160_dev* sensor)
    {
        /* Select the Output data rate, range of accelerometer sensor */
        sensor->accel_cfg.range = BMI160_ACCEL_RANGE_8G;
        sensor->gyro_cfg.range = BMI160_GYRO_RANGE_500_DPS;
        int8_t status = bmi160_set_sens_conf(sensor);
        if (BMI160_OK != status)
        {
            MTB_HALT("Error updating the IMU sensor configuration.\n");
        }
    }
#endif


/*******************************************************************************
* Function Name: imu_init
********************************************************************************
* Summary:
* This initializes the IMU on the selected shield for either I2C or SPI
* communication based on how the board is wired up. It uses mostly the default
* configuration, except changes the Accelerometer range to 8G and the Gyroscope
* range to be 500 DPS.
*
* Parameters:
*   motion_sensor   Reference to the motion sensor instance that is being
*                   initialized here
******************************************************************************/
void imu_init(mtb_imu_t* motion_sensor)
{
    cy_rslt_t result;

#ifdef AI_KIT
    static const cyhal_i2c_cfg_t i2c_cfg = {
        .is_slave        = false,
        .address         = 0,
        .frequencyhal_hz = IMU_I2C_FREQUENCY,
    };
    /* Initialize the I2C master interface for BMI160 motion sensor */
    result = cyhal_i2c_init(&i2c_obj, (cyhal_gpio_t) CYBSP_I2C_SDA,
            (cyhal_gpio_t) CYBSP_I2C_SCL, NULL);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the I2C interface.\n");
    result = cyhal_i2c_configure(&i2c_obj, &i2c_cfg);
    MTB_HALT_IF_ERROR(result, "Unable to configure the I2C interface.\n");
    result = imu_i2c_init(motion_sensor, &i2c_obj, IMU_I2C_ADDRESS);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the IMU over I2C.\n");

    result = imu_config_default(motion_sensor);
    MTB_HALT_IF_ERROR(result, "Unable to apply the default sensor configuration.\n");

    update_sensor_ranges_bmi270(&(imu_get_sensor(motion_sensor)));
#else
#if (IMU_INTERFACE_I2C == IMU_INTERFACE_SELECTED)
    static const cyhal_i2c_cfg_t i2c_cfg = {
        .is_slave        = false,
        .address         = 0,
        .frequencyhal_hz = IMU_I2C_FREQUENCY,
    };
    /* Initialize the I2C master interface for BMI160 motion sensor */
    result = cyhal_i2c_init(&i2c_obj, IMU_I2C_SDA, IMU_I2C_SCL, NULL);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the I2C interface.\n");
    result = cyhal_i2c_configure(&i2c_obj, &i2c_cfg);
    MTB_HALT_IF_ERROR(result, "Unable to configure the I2C interface.\n");
    result = imu_i2c_init(motion_sensor, &i2c_obj, IMU_I2C_ADDRESS);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the IMU over I2C.\n");
#elif (IMU_INTERFACE_SPI == IMU_INTERFACE_SELECTED)
    /* Initialize SPI for IMU communication */
    result = cyhal_spi_init(&spi_obj, IMU_SPI_MOSI, IMU_SPI_MISO, IMU_SPI_SCK, NC,
        NULL, 8, CYHAL_SPI_MODE_00_MSB, false);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the SPI interface.\n");
    result = cyhal_spi_set_frequency(&spi_obj, IMU_SPI_FREQUENCY);
    MTB_HALT_IF_ERROR(result, "Unable to set the SPI interface frequency.\n");
    result = cyhal_gpio_init(CYBSP_SPI_CS, CYHAL_GPIO_DIR_OUTPUT, CYHAL_GPIO_DRIVE_STRONG, 1);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the SPI slave select GPIO.\n");
    result = imu_spi_init(motion_sensor, &spi_obj, CYBSP_SPI_CS);
    MTB_HALT_IF_ERROR(result, "Unable to initialize the IMU over SPI.\n");
#endif

    result = imu_config_default(motion_sensor);
    MTB_HALT_IF_ERROR(result, "Unable to apply the default sensor configuration.\n");

    update_sensor_ranges_bmi160(&(imu_get_sensor(motion_sensor)));
#endif

}
