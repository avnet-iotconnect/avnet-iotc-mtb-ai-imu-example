/******************************************************************************
* File Name:   utils.h
*
* Description: This file contains basic utilities used by the code example.
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

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "cy_result.h"
#include "cy_utils.h"
#include "cyhal_system.h"
#include "shields.h"

void imu_init(mtb_imu_t* motion_sensor);

static inline void MTB_HALT(const char* message)
{
    printf("%s", message);
    /* Give time for the message to be printed */
    cyhal_system_delay_ms(100);
    CY_HALT();
}

static inline void MTB_HALT_IF_ERROR(cy_rslt_t result, const char* message)
{
    cy_rslt_decode_t decoded;
    decoded.raw = result;
    if (CY_RSLT_SUCCESS != decoded.raw)
    {
        printf("Error: 0x%08" PRIx32 ": type: %d module: 0x%04X code: 0x%04X\n",
            (uint32_t)result, decoded.type, decoded.module, decoded.code);
        MTB_HALT(message);
    }
}
