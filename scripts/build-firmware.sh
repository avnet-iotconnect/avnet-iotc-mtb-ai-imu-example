#!/bin/bash

# this script can be used to automatically build the application with MTB command line

set -e

if [ -z "${APP_PATH}" ]; then
  APP_PATH=${PWD}
fi

if [ -z "${BUILD_DIR}" ]; then
  BUILD_DIR=/tmp/build
fi

if [ -z "${ARTIFACTS_DIR}" ]; then
  ARTIFACTS_DIR=${APP_PATH}/artifacts
fi

mkdir -p "${BUILD_DIR}"
mkdir -p "${ARTIFACTS_DIR}"

#############################
cd "${BUILD_DIR}"

project-creator-cli --board-id CY8CKIT-062S2-AI --app-path "${APP_PATH}" --user-app-name avnet-iotc-mtb-ai-imu-example

cd avnet-iotc-mtb-ai-imu-example

###############
make build

cp ./build/last_config/avnet-iotc-mtb-ai-imu-example.hex "${ARTIFACTS_DIR}"/


