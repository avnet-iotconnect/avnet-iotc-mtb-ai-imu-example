/* SPDX-License-Identifier: MIT
 * Copyright (C) 2024 Avnet
 * Authors: Nikola Markovic <nikola.markovic@avnet.com>, Shu Liu <shu.liu@avnet.com> et al.
 */

#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include "iotconnect.h"

typedef int (*IotcX509CredentialsGenerate)(char *crt_buff, size_t crt_buff_size, char* key_buff, size_t key_buff_size);

int app_eeprom_data_init(void);

void app_eeprom_data_do_user_input(IotcX509CredentialsGenerate x509_creds_generate_cb);

bool app_eeprom_data_is_valid(void);

IotConnectConnectionType app_eeprom_data_get_platform(IotConnectConnectionType default_value);
const char* app_eeprom_data_get_cpid(const char* default_value);
const char* app_eeprom_data_get_env(const char* default_value);
const char* app_eeprom_data_get_wifi_ssid(const char* default_value);
const char* app_eeprom_data_get_wifi_pass(const char* default_value);
const char* app_eeprom_data_get_certificate(const char* default_value);
const char* app_eeprom_data_get_private_key(const char* default_value);
