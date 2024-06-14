/******************************************************************************
* File Name:   shields.h
*
* Description: This file contains macros defining the pins to use for
* interfacing with the sensors based on supported Infineon Arduino shields.
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

#define IMU_INTERFACE_I2C                   (0)
#define IMU_INTERFACE_SPI                   (1)
#if defined(SENSE_SHIELDv1)
    #include "cy8ckit_028_sense_pins.h"
    #include "mtb_bmx160.h"

    #define IMU_INTERFACE_SELECTED          (IMU_INTERFACE_SPI)

    #define IMU_SPI_SCK                     (CY8CKIT_028_SENSE_PIN_SPI_SCK)
    #define IMU_SPI_MISO                    (CY8CKIT_028_SENSE_PIN_SPI_MISO)
    #define IMU_SPI_MOSI                    (CY8CKIT_028_SENSE_PIN_SPI_MOSI)
    #define IMU_SPI_CS                      (CY8CKIT_028_SENSE_PIN_SPI_CS)

    #define IMU_I2C_ADDRESS                 (MTB_BMX160_ADDRESS_DEFAULT)
    #define IMU_I2C_SCL                     (CY8CKIT_028_SENSE_PIN_I2C_SCL)
    #define IMU_I2C_SDA                     (CY8CKIT_028_SENSE_PIN_I2C_SDA)
    #define IMU_INT_1                       (CY8CKIT_028_SENSE_PIN_IMU_INT_1)
    #define IMU_INT_2                       (CY8CKIT_028_SENSE_PIN_IMU_INT_2)

    #define PDM_CLK                         (CY8CKIT_028_SENSE_PIN_PDM_CLK)
    #define PDM_DATA                        (CY8CKIT_028_SENSE_PIN_PDM_DATA)

    #define PSEN_INT                        (CY8CKIT_028_SENSE_PIN_PSEN_INT)

    #define imu_i2c_init(obj, i2c, addr)    mtb_bmx160_init_i2c(obj, i2c, addr)
    #define imu_spi_init(obj, spi, cs)      mtb_bmx160_init_spi(obj, spi, cs)
    #define imu_config_default(obj)         mtb_bmx160_config_default(obj)
    #define imu_read(obj, data)             mtb_bmx160_read(obj, data)
    #define imu_get_sensor(mtb_obj)         (mtb_obj->sensor1)

    typedef mtb_bmx160_t                    mtb_imu_t;
    typedef mtb_bmx160_data_t               mtb_imu_data_t;
#elif defined(SENSE_SHIELDv2)
    #include "cy8ckit_028_sense_pins.h"
    #include "mtb_bmi160.h"

    #define IMU_INTERFACE_SELECTED          (IMU_INTERFACE_SPI)

    #define IMU_SPI_SCK                     (CY8CKIT_028_SENSE_PIN_SPI_SCK)
    #define IMU_SPI_MISO                    (CY8CKIT_028_SENSE_PIN_SPI_MISO)
    #define IMU_SPI_MOSI                    (CY8CKIT_028_SENSE_PIN_SPI_MOSI)
    #define IMU_SPI_CS                      (CY8CKIT_028_SENSE_PIN_SPI_CS)

    #define IMU_I2C_ADDRESS                 (MTB_BMI160_ADDRESS_DEFAULT)
    #define IMU_I2C_SCL                     (CY8CKIT_028_SENSE_PIN_I2C_SCL)
    #define IMU_I2C_SDA                     (CY8CKIT_028_SENSE_PIN_I2C_SDA)
    #define IMU_INT_1                       (CY8CKIT_028_SENSE_PIN_IMU_INT_1)
    #define IMU_INT_2                       (CY8CKIT_028_SENSE_PIN_IMU_INT_2)

    #define PDM_CLK                         (CY8CKIT_028_SENSE_PIN_PDM_CLK)
    #define PDM_DATA                        (CY8CKIT_028_SENSE_PIN_PDM_DATA)

    #define PSEN_INT                        (CY8CKIT_028_SENSE_PIN_PSEN_INT)

    #define imu_i2c_init(obj, i2c, addr)    mtb_bmi160_init_i2c(obj, i2c, addr)
    #define imu_spi_init(obj, spi, cs)      mtb_bmi160_init_spi(obj, spi, cs)
    #define imu_config_default(obj)         mtb_bmi160_config_default(obj)
    #define imu_read(obj, data)             mtb_bmi160_read(obj, data)
    #define imu_get_sensor(mtb_obj)         (mtb_obj->sensor)

    typedef mtb_bmi160_t                    mtb_imu_t;
    typedef mtb_bmi160_data_t               mtb_imu_data_t;
#elif defined(EPD_SHIELD)
    #include "cy8ckit_028_epd_pins.h"
    #include "mtb_bmi160.h"

    #define IMU_INTERFACE_SELECTED          (IMU_INTERFACE_I2C)

    #define IMU_I2C_ADDRESS                 (MTB_BMI160_DEFAULT_ADDRESS)
    #define IMU_I2C_SCL                     (CY8CKIT_028_EPD_PIN_IMU_I2C_SCL)
    #define IMU_I2C_SDA                     (CY8CKIT_028_EPD_PIN_IMU_I2C_SDA)
    #define IMU_INT_1                       (CY8CKIT_028_EPD_PIN_IMU_INT_1)
    #define IMU_INT_2                       (CY8CKIT_028_EPD_PIN_IMU_INT_2)

    #define PDM_CLK                         (CY8CKIT_028_EPD_PIN_PDM_CLK)
    #define PDM_DATA                        (CY8CKIT_028_EPD_PIN_PDM_DATA)

    #define imu_i2c_init(obj, i2c, addr)    mtb_bmi160_init_i2c(obj, i2c, addr)
    #define imu_config_default(obj)         mtb_bmi160_config_default(obj)
    #define imu_read(obj, data)             mtb_bmi160_read(obj, data)
    #define imu_get_sensor(mtb_obj)         (mtb_obj->sensor)

    typedef mtb_bmi160_t                    mtb_imu_t;
    typedef mtb_bmi160_data_t               mtb_imu_data_t;
#elif defined(TFT_SHIELD)
    #include "cy8ckit_028_tft_pins.h"
    #include "mtb_bmi160.h"

    #define IMU_INTERFACE_SELECTED          (IMU_INTERFACE_I2C)

    #define IMU_I2C_ADDRESS                 (MTB_BMI160_DEFAULT_ADDRESS)
    #define IMU_I2C_SCL                     (CY8CKIT_028_TFT_PIN_IMU_I2C_SCL)
    #define IMU_I2C_SDA                     (CY8CKIT_028_TFT_PIN_IMU_I2C_SDA)
    #define IMU_I2C_INT_1                   (CY8CKIT_028_TFT_PIN_IMU_INT_1)
    #define IMU_I2C_INT_2                   (CY8CKIT_028_TFT_PIN_IMU_INT_2)

    #define PDM_CLK                         (CY8CKIT_028_TFT_PIN_PDM_CLK)
    #define PDM_DATA                        (CY8CKIT_028_TFT_PIN_PDM_DATA)

    #define imu_i2c_init(obj, i2c, addr)    mtb_bmi160_init_i2c(obj, i2c, addr)
    #define imu_config_default(obj)         mtb_bmi160_config_default(obj)
    #define imu_read(obj, data)             mtb_bmi160_read(obj, data)
    #define imu_get_sensor(mtb_obj)         (mtb_obj->sensor)

    typedef mtb_bmi160_t                    mtb_imu_t;
    typedef mtb_bmi160_data_t               mtb_imu_data_t;

#elif defined(AI_KIT)
    #include "mtb_bmi270.h"

    #define IMU_I2C_ADDRESS                 (MTB_BMI270_ADDRESS_DEFAULT)
    #define imu_i2c_init(obj, i2c, address) mtb_bmi270_init_i2c(obj, i2c, address)
    #define imu_config_default(obj)         mtb_bmi270_config_default(obj)
    #define imu_read(obj, data)             mtb_bmi270_read(obj, data)
    #define imu_get_sensor(mtb_obj)         (mtb_obj->sensor)

    typedef mtb_bmi270_t                    mtb_imu_t;
    typedef mtb_bmi270_data_t               mtb_imu_data_t;
#else
    #error "Undefined interface for sensors. Expecting either the [SENSEv1|SENSEv2|TFT|EPD]_SHILED or AI_KIT to be defined in the Makefile"
#endif
