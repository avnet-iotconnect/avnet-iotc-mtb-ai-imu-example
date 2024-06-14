## Introduction

This document demonstrates the steps of setting up the Infineon PSoC&trade; 6 boards
for connecting to Avnet's IoTConnect Platform. Supported boards are listed in 
the [README.md](README.md).

The project has been tested with the Eclipse option in Project Creator and only supports the ARM_GCC (Eclipse default) toolchain.

For an example with OTA support, you must use the earlier version of this
software under the `release-v4.0.0` label, along with ModusToolbox&trade; 3.1.
and [Local Manifest Setup](DEVELOPER_LOCAL_SETUP.md#local-manifest-setup)

## Prerequisites
* PC with Windows. The project is tested with Windows 10, though the setup should work with Linux or Mac as well.
* USB-A to micro-USB data cable
* 2.4GHz WiFi Network
* A serial terminal application such as [Tera Term](https://ttssh2.osdn.jp/index.html.en) or a browser-based application like [Google Chrome Labs Serial Terminal](https://googlechromelabs.github.io/serial-terminal/)
* A registered [myInfineon Account](https://www.infineon.com/sec/login)

For OTA Support, you must use this application with ModusToolbox&trade; 3.1. 

## Hardware Setup
* Connect the board to a USB port on your PC. A new USB device should be detected.
Firmware logs will be available on that COM port.
* Open the Serial Terminal application and configure as shown below:
  * Port: (Select the COM port with the device)
  * Speed: `115200`
  * Data: `8 bits`
  * Parity: `none`
  * Stop Bits: `1`
  * Flow Control: `none`
  
## Building the Software

> [!NOTE]
> If you wish to contribute to this project or work with your own git fork,
> or evaluate an application version that is not yet released, the setup steps will change 
> the setup steps slightly.
> In that case, read [DEVELOPER_LOCAL_SETUP.md](./DEVELOPER_LOCAL_SETUP.md) 
> before continuing to the steps below.
> 
> Follow the [Contributing Guidelines](https://github.com/avnet-iotconnect/iotc-c-lib/blob/master/CONTRIBUTING.md) 
> if you are contributing to this project.

- Download, install [ModusToolbox&trade; software](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
version 3.2 or later. Install the development suite with Modus Toolbox&trade; Setup. 
Ensure that *Modus Toolbox&trade; Tools Package* and *Modus Toolbox&trade; Programming tools* are selected during setup. 
The setup tool may require you to log into your Infineon account.
- Open the Project Creator.
- Select one of the supported boards from [README.md](README.md) and click *Next*.
- At the top of the window, choose a path where the project will be installed.
On Windows, ensure that this path is *short* starting from a root of a drive like *C:\iotc-xensiv*,
or else ong paths will trigger the 256 Windows path limit and cause compiling errors. Refer to the
[Troubleshooting](#troubleshooting) section of this document for more information.
- Select *Eclipse IDE for Modus Toolbox&trade;* in the pulldown below the installation path. 
VsCode integration and other tools may work, but actively tested and not a part of this guide.
- Select the *Avnet IoTConnect Optiga Example* from the *Peripherals* Category.
- Click the *Create* button at the bottom of the screen.
- Open the installed Eclipse IDE For Modus Toolbox&trade; application.
- When prompted for the workspace, choose an arbitrary location for your workspace and click the *Launch* button.
- Click the **Import Existing Application In-Place** link in the *Quick Panel* at the bottom left of the window.
- Select the directory chosen during the Project Creator step above (*C:/avt-demo*, for example).

> [!TIP]
> The Compilation Database Parser makes it so that Eclipse IDE understands compile time preprocessor defines
> applied to the project while editing code.
> Depending on the development stage, one can improve Eclipse build time and responsiveness by disabling it using this method:
> Right-click the project and select Properties > C/C++ General >Preprocessor Include Paths > Providers, 
> and deselect the Compilation Database Parser check box.

- At this point you should be able to build and run the application by clicking the application first in 
the project explorer panel and then clicking the *application-name-Debug* or *Program* *KitProg3_MiniProg4 
launch configurations in *Quick Panel* at the bottom left of the IDE screen.
- Examine the console messages on the serial terminal. Once the device boots up,
it will print the auto-generated DUID (Device Unique ID) that you will use to 
create the device in the steps at [Cloud Account Setup](#cloud-account-setup) below in this guide:
``` 
Generated device unique ID (DUID) is: psoc6-xxxxxxxx
```
- Once the Cloud Account Setup is complete,
At **Avnet_IoTConnect_Optiga_Example/config/** modify **app_config.h** per your
IoTConnect device setup **wifi_config.h** per your WiFi connection settings.
- Debug or Program the application.

## Cloud Account Setup
An IoTConnect account is required.  If you need to create an account, a free 2-month subscription is available.

Please follow the 
[Creating a New IoTConnect Account](https://github.com/avnet-iotconnect/avnet-iotconnect.github.io/blob/main/documentation/iotconnect/subscription/subscription.md)
guide and select one of the two implementations of IoTConnect: 
* [AWS Version](https://subscription.iotconnect.io/subscribe?cloud=aws)  
* [Azure Version](https://subscription.iotconnect.io/subscribe?cloud=azure)  

* Be sure to check any SPAM folder for the temporary password.

### Acquire IoTConnect Account Information

* Login to IoTConnect using the corresponding link below to the version to which you registered:  
    * [IoTConnect on AWS](https://console.iotconnect.io) 
    * [IoTConnect on Azure](https://portal.iotconnect.io)

* The Company ID (**CPID**) and Environment (**ENV**) variables are required to be stored into the device. Take note of these values for later reference.
<details><summary>Acquire <b>CPID</b> and <b>ENV</b> parameters from the IoTConnect Key Vault and save for later use</summary>
<img style="width:75%; height:auto" src="https://github.com/avnet-iotconnect/avnet-iotconnect.github.io/blob/bbdc9f363831ba607f40805244cbdfd08c887e78/assets/cpid_and_env.png"/>
</details>


#### IoTConnect Device Template Setup

An IoTConnect *Device Template* will need to be created or imported.
* Download the premade  [Device Template](files/psoc6-device-template.json).
* Import the template into your IoTConnect instance:  [Importing a Device Template](https://github.com/avnet-iotconnect/avnet-iotconnect.github.io/blob/main/documentation/iotconnect/import_device_template.md) guide  
> **Note:**  
> For more information on [Template Management](https://docs.iotconnect.io/iotconnect/user-manuals/devices/template-management/) please see the [IoTConnect Documentation](https://iotconnect.io) website.

#### IoTConnect Device Creation

* Create a new device in the IoTConnect portal. (Follow the [Create a New Device](https://github.com/avnet-iotconnect/avnet-iotconnect.github.io/blob/main/documentation/iotconnect/create_new_device.md) guide for a detailed walkthrough.)
* Enter the **DUID** noted from earlier into the *Unique ID* field
* Enter the same DUID or descriptive name of your choosing as *Display Name* to help identify your device
* Select the template from the dropdown box that was just imported ("psoc6mtb")
* Ensure "Auto-generated" is selected under *Device certificate*
* Click **Save & View**
* In the info panel, click the Connection Infohyperink on top right and 
download the certificate by clicking the download icon on the top right
![download-cert.png](media/download-cert.png).
* You will need to open the device certificate and private key files and 
provide them in configs/app_config.h formatted specified as a C string #define like so:
  ```
  #define IOTCONNECT_DEVICE_CERT \
  "-----BEGIN CERTIFICATE-----\n" \
  "MIICwTCCAakCFFUmScR+Y+XTcu0YKMQcFDXSENLKMA0GCSqGSIb3DQEBCwUAMB0x\n" \
  "GzAZBgNVBAMMEmF2dGRzLWlvdGNlZjJmNDAyMjAeFw0yNDA1MDIxOTEyMzRaFw0y\n" \
  "NTA1MDIxOTEyMzRaMB0xGzAZBgNVBAMMEmF2dGRzLWlvdGNlZjJmNDAyMjCCASIw\n" \
  "DQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBANA1q0MJwVLGn2uz7O/I2Wo80vnf\n" \
  "ho+U/LW7bHW3JkzrkWIsc2cnT9fDhbSHmUkNlj5yUl+DtsM5LlAV/QO+EHd1xubU\n" \
  "fmtXmk+/vB5g4OhGAI                               CvxlEqm2jW239sU\n" \
  "po153s2XPfO0A0NN8L                               PPTVVA/SlwmuKOp\n" \
  "YdtfTzhdBNiPtnt6xP      THIS IS AN EXAMPLE       mP25wfeCeNh1e64\n" \
  "KWMVsY1wBsPLsC7KmC                               aIaEJsTRiECAwEA\n" \
  "ATANBgkqhkiG9w0BAQ                               quxEn1IkGjmNF2I\n" \
  "m/3+BM/2qPTxZVnfZfgKr3xD3hedymY0JRiKHKZGVWQSClobrbL5p6DraYBwWSFe\n" \
  "h/lKhhBl0quu1vqXPhbMQaVcrBh4NGU8uDi3kezytqVhewR7wru/V3pdwvSer+Am\n" \
  "qr5Sg/2HGybLHGsYhiRqU6bEYhPUzmQJs5FBR9HPd1xsME0qP6MW9FnR7S06G+z4\n" \
  "UkWMseIlcxY6mGViLZGS362rAOAFQE9QYA9qdWyM+AIvjZjlQCbkTOiaEd6GXQIU\n" \
  "khPBBRXBKbDpQ02LgX6tsJUEbGbnPC94LfwnkTuVx/CFKWZfmg==\n" \
  "-----END CERTIFICATE-----"
  ```
  The same format needs to be used for the private key as `#define IOTCONNECT_DEVICE_KEY`

At this point, the device can be reprogrammed with the newly built firmware.

## OTA Support

This project supports IoTConnect OTA via the ota-update library with the CY8CPROTO-062-4343W board.

The port of the OTA feature is rudimentary for purpose demonstration and not recommended for production. 
If you wish to support the OTA functionality for your board, please learn more from the README of the
[mtb-example-ota-https](https://github.com/Infineon/mtb-example-ota-https) sample.

> [!NOTE]  
> The OTA feature is not supported with CY8CKIT-062-WIFI-BT

In order to add ioTConnect OTA support to this project, 
do the following steps once you have opened this project in Eclipse:

* Select this application in the top left panel and open the Library Manager from the bottom left Quick Panel. 
Note that the library manager may take some time appear in the quick panel.
* Clik the *Add Library* button and add **ota-update** version *release-v4.1.0* 
 and **ota-bootloader-abstraction** version *release-v1.1.0* libraries.
* Locate the `OTA_SUPPORT=0` line in the Makefile and set OTA_SUPPORT to 1:
```makefile
OTA_SUPPORT=1
```
* It is necessary to modify the linker files so that the image components are placed in the correct flash section:
  * Locate the CM4 component template files for your board in the templates-ota directory.
  For example, for CY8CPROTO-062-4343W they will be at templates-ota/TARGET_CY8CPROTO-062-4343W/COMPONENT_CM4/TOOLCHAIN_GCC_ARM
  * Replace your BSP files with the files from the templates-ota directory. 
  For CY8CPROTO-062-4343W, your corresponding BSP files would be located at bsps/TARGET_**APP**_CY8CPROTO-062-4343W/COMPONENT_CM4/TOOLCHAIN_GCC_ARM/
  * If you cloned this project's repo or have your own repository, this part of the setup can be streamlined by simply
  renaming the templates-ota directory to ``templates`` before the project is imported with Project Creator. 
  is done with intention 

> The content of the templates-ota directory is not compatible with OTA_SUPPORT being disabled, so if you need to 
> switch to OTA_SUPPORT=0, it is recommended that you re-create this project with the Project Creator. 

We now need to build the *MCUboot-Based Basic Bootloader* application separately and load it onto the board.
The following steps are compatible with the bootloader sample application version *release-7.0.0*
and if any issues are encountered, you should clone 
the [mtb-example-mcuboot-basic](https://github.com/Infineon/mtb-example-mcuboot-basic/tree/release-v7.0.0) 
release-v7.0.0 tag of the application and use the steps similar to the [DEVELOPER_LOCAL_SETUP.md](DEVELOPER_LOCAL_SETUP.md)
to import the local project with Project Creator.

* Use the Project Creator to import the *MCUboot-Based Basic Bootloader* application into a separate workspace/directory.
* Copy the *psoc62_2m_ext_swap_single.json* flashmap JSON file from this project in the [flashmap](flashmap) directory into the \<MCUboot>/flashmap director.
* Modify the value of the FLASH_MAP variable in the \<MCUboot>/user_config.mk file to use *psoc62_2m_ext_swap_single.json*
* Connect the board to your PC using the provided USB cable through the KitProg3 USB connector. 
* Select the *MCUboot-Based_Basic_Bootloader.bootloader_app* in the \<MCUboot> project in the left panel and open the Eclipse terminal window the bottom panel.
The terminal should be in the MCUboot-Based_Basic_Bootloader/bootloader_app directory.
* From the terminal, execute the `make program_proj` command to build and program the MCUboot-based bootloader application.

You can now build and upload the basic example application. 
If this is done correctly, when starting up the board you should see the bootloader messages followed by the application startup messages. 
