## Introduction

This demo project is the integration of the 
Infineon's [Machine learning: Imagimob model deployment](https://github.com/Infineon/mtb-example-ml-imagimob-deploy/tree/release-v1.1.0)
and Avnet's [IoTConnect Modus Toolbox&trade; Basic Sample](https://github.com/avnet-iotconnect/avnet-iotc-mtb-basic-example/tree/release-v6.0.0)
. It runs the Human Activity Detection AI algorithm and then AI model's recognized class is reported to IoTConnect.

This project currently supports the [CY8CKIT-062S2-AI](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ckit-062s2-ai/)

The project supports only Eclipse with GCC_ARM compiler.


## Building the Project

[Wacth an Overview](https://saleshosted.z13.web.core.windows.net/media/ifx/videos/IFX%20Modus%20with%20IoTConnect.mp4) of creating a new project with IoTConnect in ModusToolbox.

To build the project, please refer to the 
[IoTConnect Modus Toolbox&trade; Basic Sample Developer Guide](https://github.com/avnet-iotconnect/avnet-iotc-mtb-basic-example/tree/release-v6.0.0/DEVELOPER_GUIDE.md) 
and note the following:
- Once Modus Toolbox has been installed, the 
    [ModusToolbox&trade; for Machine Learning](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.modustoolboxpackmachinelearning) 
    software should be installed as well.
- If using the model generator, you will need to install QEMU and set up the relevant environment variables
    per [Machine Learning User Guide](https://www.infineon.com/dgdl/Infineon-Infineon-ModusToolbox_Machine_Learning_User_Guide-UserManual-v02_00-EN-UserManual-v09_00-EN.pdf?fileId=8ac78c8c83cd308101840de7e95a09df)
- OTA is not supported.
- Use the [psoc6aiimu-device-template.json Device Template](files/psoc6aiimu-device-template.json) instead of the Basic Sample's template.

## Running the Demo

See more on how to orient the board for detection at the
Infineon's [Machine learning: Imagimob model deployment](https://github.com/Infineon/mtb-example-ml-imagimob-deploy/tree/release-v1.1.0) 
README file. We recommend to plug the board into a power cell while testing.

The application sends data once every second, but the AI model recognizes human activity several times
per second. If at the time reporting data to IoTConnect the activity is not recognized, he **class** value will be reported as **unlabelled**.
If the activity is reconginized, the **class** value will be reported as either:
* sitting
* standing
* walking
* walking
* jumping

The model will report different **confidence** percentages for each case, and the application will report
the highest confidence class along with its confidence percentage.

Along these values, the data will contain the raw accelerometer reading based on board's orientation and movement 
as an object value **accel**, with **x**, **y** and **z** values.

## Other Supported Boards

The project  can be modified to support the original Infineon's project supported boards along with the 
[CY8CKIT-028-SENSE shield](https://www.infineon.com/cms/en/product/evaluation-boards/cy8ckit-028-sense/) and similar boards.
If introducing support for those boards, please make note that [.cyignore](.cyignore) currently ignores shield files and 
that CY_IGNORE logic in the makefile has no effect.



