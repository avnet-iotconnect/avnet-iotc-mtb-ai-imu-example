################################################################################
# \file Makefile
# \version 1.0
#
# \brief
# Top-level application make file.
#
################################################################################
# \copyright
# Copyright 2018-2021, Cypress Semiconductor Corporation (an Infineon company)
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
################################################################################

################################################################################
# Basic Configuration
################################################################################

# Type of ModusToolbox Makefile Options include:
#
# COMBINED    -- Top Level Makefile usually for single standalone application
# APPLICATION -- Top Level Makefile usually for multi project application
# PROJECT     -- Project Makefile under Application
MTB_TYPE=COMBINED

# Target board/hardware (BSP).
# To change the target, it is recommended to use the Library manager
# ('make modlibs' from command line), which will also update Eclipse IDE launch
# configurations. If TARGET is manually edited, ensure TARGET_<BSP>.mtb with a
# valid URL exists in the application, run 'make getlibs' to fetch BSP contents
# and update or regenerate launch configurations for your IDE.
TARGET=APP_CY8CKIT-062S2-AI

# Name of application (used to derive name of final linked file).
#
# If APPNAME is edited, ensure to update or regenerate launch
# configurations for your IDE.
APPNAME=iotc-modustoolbox-example

# Name of toolchain to use. Options include:
#
# GCC_ARM -- GCC provided with ModusToolbox software
# ARM     -- ARM Compiler (must be installed separately)
# IAR     -- IAR Compiler (must be installed separately)
#
# See also: CY_COMPILER_PATH below
TOOLCHAIN=GCC_ARM

# Default build configuration. Options include:
#
# Debug -- build with minimal optimizations, focus on debugging.
# Release -- build with full optimizations
# Custom -- build with custom configuration, set the optimization flag in CFLAGS
#
# If CONFIG is manually edited, ensure to update or regenerate launch configurations
# for your IDE.
CONFIG=Debug

# Default value for CORE = CM4
# You can change it to CM0P to port your application to CM0P.
#
CORE=CM4

# If set to "true" or "1", display full command-lines when building.
VERBOSE=

##### OTA MAKEFILE MERGED FROM mtb-example-ota-https ######
# Set Platform type
# E.g. PLATFORM=PSOC_062_512K, PLATFORM=PSOC_062_2M,  PLATFORM=XMC7200
ifeq ($(TARGET), APP_KIT_XMC72_EVK_MUR_43439M2)
PLATFORM=XMC7200
else
ifeq ($(TARGET), APP_CY8CPROTO-062S3-4343W)
PLATFORM=PSOC_062_512K
else
PLATFORM=PSOC_062_2M
endif
endif

# Core processor
ifneq ($(PLATFORM), XMC7200)
CORE=CM4
else
CORE=CM7
endif
##### END OTA MAKEFILE MERGED FROM mtb-example-ota-https ######

################################################################################
# Advanced Configuration
################################################################################

# Enable optional code that is ordinarily disabled by default.
#
# Available components depend on the specific targeted hardware and firmware
# in use. In general, if you have
#
#    COMPONENTS=foo bar
#
# ... then code in directories named COMPONENT_foo and COMPONENT_bar will be
# added to the build
#
COMPONENTS=FREERTOS LWIP MBEDTLS SECURE_SOCKETS

# Like COMPONENTS, but disable optional code that was enabled by default.
DISABLE_COMPONENTS=

# By default the build system automatically looks in the Makefile's directory
# tree for source code and builds it. The SOURCES variable can be used to
# manually add source code to the build process from a location not searched
# by default, or otherwise not found by the build system.
SOURCES=

# Like SOURCES, but for include directories. Value should be paths to
# directories (without a leading -I).
INCLUDES=./configs

DEFINES=

##### IMAGIMOB DEPLOY DEMO MAKEFILE MERGED FROM mtb-example-ml-imagimob-deploy ######
# Exclude redundant files based on shield selection
ifneq (,$(findstring TFT_SHIELD,$(DEFINES)))
CY_IGNORE+= $(SEARCH_CY8CKIT-028-EPD) $(SEARCH_CY8CKIT-028-SENSE) \
		$(SEARCH_sensor-motion-bmi270) $(SEARCH_sensor-orientation-bmx160) \
        $(SEARCH_BMI270_SensorAPI) $(SEARCH_BMM150-Sensor-API)
endif
ifneq (,$(findstring EPD_SHIELD,$(DEFINES)))
CY_IGNORE+= $(SEARCH_CY8CKIT-028-SENSE) $(SEARCH_CY8CKIT-028-TFT) \
		$(SEARCH_sensor-motion-bmi270) $(SEARCH_sensor-orientation-bmx160) \
        $(SEARCH_BMI270_SensorAPI) $(SEARCH_BMM150-Sensor-API)
endif
ifneq (,$(findstring SENSE_SHIELDv1,$(DEFINES)))
DEFINES+=BMI160_CHIP_ID=UINT8_C\(0xD8\)
CY_IGNORE+= $(SEARCH_CY8CKIT-028-EPD) $(SEARCH_CY8CKIT-028-TFT) \
		$(SEARCH_sensor-motion-bmi270) $(SEARCH_sensor-motion-bmi160) \
        $(SEARCH_BMI270_SensorAPI)
endif
ifneq (,$(findstring SENSE_SHIELD_v2,$(DEFINES)))
CY_IGNORE+= $(SEARCH_CY8CKIT-028-EPD) $(SEARCH_CY8CKIT-028-TFT) \
		$(SEARCH_sensor-motion-bmi270) $(SEARCH_sensor-orientation-bmx160) \
        $(SEARCH_BMI270_SensorAPI) $(SEARCH_BMM150-Sensor-API)
endif
ifneq (,$(findstring AI_KIT,$(DEFINES)))
CY_IGNORE+= $(SEARCH_CY8CKIT-028-EPD) $(SEARCH_CY8CKIT-028-SENSE) $(SEARCH_CY8CKIT-028-TFT) \
		$(SEARCH_sensor-motion-bmi160) $(SEARCH_sensor-orientation-bmx160) \
        $(SEARCH_BMI160_driver) $(SEARCH_BMM150-Sensor-API)
endif
##### END IMAGIMOB DEPLOY DEMO MAKEFILE MERGED FROM mtb-example-ml-imagimob-deploy ######

# Custom configuration of mbedtls library.
MBEDTLSFLAGS=MBEDTLS_USER_CONFIG_FILE='"mbedtls_user_config.h"'

# Turn off making tests for CJSON
CJSONFLAGS=ENABLE_CJSON_TEST=Off ENABLE_CJSON_UTILS=Off

# Add additional defines to the build process (without a leading -D).
DEFINES+=$(MBEDTLSFLAGS) $(CJSONFLAGS) $(IOTCLFLAGS) CYBSP_WIFI_CAPABLE CY_RETARGET_IO_CONVERT_LF_TO_CRLF
DEFINES+=CY_RTOS_AWARE

# for http client
DEFINES+=ENABLE_HTTP_CLIENT_LOGS MQTT_DO_NOT_USE_CUSTOM_CONFIG
DEFINES+=HTTP_DO_NOT_USE_CUSTOM_CONFIG
# for sntp
DEFINES+=SNTP_SERVER_DNS

# Define to enable qualification code in the SDK
# This define should NOT be used in production,
# as it could make your device vulnerable to MITM attacks
# DEFINES+=IOTC_AWS_DEVICE_QUALIFICATION

# Configure response header maximum length with the specified value - HTTP
DEFINES+=HTTP_MAX_RESPONSE_HEADERS_SIZE_BYTES=2048

### MQTT SETTINGS
# Number of milliseconds to wait for a ping response to a ping
DEFINES+= MQTT_PINGRESP_TIMEOUT_MS=5000
# The number of retries for receiving CONNACK
DEFINES+= MQTT_MAX_CONNACK_RECEIVE_RETRY_COUNT=2


##### IMAGIMOB DEPLOY DEMO MAKEFILE MERGED FROM mtb-example-ml-imagimob-deploy ######
ifeq (APP_CY8CKIT-062S2-AI, $(TARGET))
DEFINES+=AI_KIT
else
# Add additional defines to the build process (without a leading -D).
# This library nativly supports being used with one of three Arduino
# compatable shield boards. To change what shield is targeted, change
# the define below. Supported values are:
# TFT_SHIELD              -- Using the 028-TFT shield
# EPD_SHIELD		      -- Using the 028-EPD shield
# SENSE_SHIELDv1            -- Using the 028-SENSE shield rev** or rev*A
# SENSE_SHIELDv2         -- Using the 028-SENSE shield rev*B or later
DEFINES+=SENSE_SHIELDv1
endif
##### END IMAGIMOB DEPLOY DEMO MAKEFILE MERGED FROM mtb-example-ml-imagimob-deploy ######


# CY8CPROTO-062-4343W board shares the same GPIO for the user button (USER BTN1)
# and the CYW4343W host wake up pin. Since this example uses the GPIO for
# interfacing with the user button, the SDIO interrupt to wake up the host is
# disabled by setting CY_WIFI_HOST_WAKE_SW_FORCE to '0'.
#
# If you wish to enable this host wake up feature, Comment DEFINES+=CY_WIFI_HOST_WAKE_SW_FORCE=0.
# If you want this feature on CY8CPROTO-062-4343W, change the GPIO pin for USER BTN
# in design/hardware & Comment DEFINES+=CY_WIFI_HOST_WAKE_SW_FORCE=0.
DEFINES+=CY_WIFI_HOST_WAKE_SW_FORCE=0

# Select softfp or hardfp floating point. Default is softfp.
VFP_SELECT=hardfp

# Additional / custom C compiler flags.
#
# NOTE: Includes and defines should use the INCLUDES and DEFINES variable
# above.
CFLAGS=

# Additional / custom C++ compiler flags.
#
# NOTE: Includes and defines should use the INCLUDES and DEFINES variable
# above.
CXXFLAGS=

# Additional / custom assembler flags.
#
# NOTE: Includes and defines should use the INCLUDES and DEFINES variable
# above.
ASFLAGS=

# Additional / custom libraries to link in to the application.
LDLIBS=

# Path to the linker script to use (if empty, use the default linker script).
LINKER_SCRIPT=

# Custom pre-build commands to run.
PREBUILD=

# Custom post-build commands to run.
POSTBUILD=

##### IMAGIMOB DEPLOY DEMO MAKEFILE MERGED FROM mtb-example-ml-imagimob-deploy ######
ifneq (AI_KIT, $(DEFINES))
PREBUILD+=$(SEARCH_sensor-orientation-bmx160)/bmx160_fix.bash "$(SEARCH_BMI160_driver)/bmi160_defs.h"
endif
##### END IMAGIMOB DEPLOY DEMO MAKEFILE MERGED FROM mtb-example-ml-imagimob-deploy ######


################################################################################
# Paths
################################################################################

# Relative path to the project directory (default is the Makefile's directory).
#
# This controls where automatic source code discovery looks for code.
CY_APP_PATH=

# Relative path to the shared repo location.
#
# All .mtb files have the format, <URI>#<COMMIT>#<LOCATION>. If the <LOCATION> field
# begins with $$ASSET_REPO$$, then the repo is deposited in the path specified by
# the CY_GETLIBS_SHARED_PATH variable. The default location is one directory level
# above the current app directory.
# This is used with CY_GETLIBS_SHARED_NAME variable, which specifies the directory name.
CY_GETLIBS_SHARED_PATH=../

# Directory name of the shared repo location.
#
CY_GETLIBS_SHARED_NAME=mtb_shared

# Absolute path to the compiler's "bin" directory. The variable name depends on the
# toolchain used for the build. Refer to the ModusToolbox user guide to get the correct
# variable name for the toolchain used in your build.
#
# The default depends on the selected TOOLCHAIN (GCC_ARM uses the ModusToolbox
# software provided compiler by default).
CY_COMPILER_GCC_ARM_DIR=


# Locate ModusToolbox helper tools folders in default installation
# locations for Windows, Linux, and macOS.
CY_WIN_HOME=$(subst \,/,$(USERPROFILE))
CY_TOOLS_PATHS ?= $(wildcard \
    $(CY_WIN_HOME)/ModusToolbox/tools_* \
    $(HOME)/ModusToolbox/tools_* \
    /Applications/ModusToolbox/tools_*)

# If you install ModusToolbox software in a custom location, add the path to its
# "tools_X.Y" folder (where X and Y are the version number of the tools
# folder). Make sure you use forward slashes.
CY_TOOLS_PATHS+=

# Default to the newest installed tools folder, or the users override (if it's
# found).
CY_TOOLS_DIR=$(lastword $(sort $(wildcard $(CY_TOOLS_PATHS))))

ifeq ($(CY_TOOLS_DIR),)
$(error Unable to find any of the available CY_TOOLS_PATHS -- $(CY_TOOLS_PATHS). On Windows, use forward slashes.)
endif

$(info Tools Directory: $(CY_TOOLS_DIR))

include $(CY_TOOLS_DIR)/make/start.mk
