#!/bin/sh

# Fail build if any command fails
set -e

# Prepare separate directory to prevent changing user's files
cp -R /usr/code/* /usr/builds

# Install User Function Dependencies if requirements.txt exists
cd /usr/builds
python3 -m venv runtime-env
source runtime-env/bin/activate
if [ -f "requirements.txt" ]; then
    pip install --no-cache-dir -r requirements.txt
fi

# Merge the requirements from server and user code
cd /usr/local/src/
pip install --no-cache-dir -r requirements.txt

# Finish build by preparing tar to use for starting the runtime
cd /usr/builds
tar --exclude code.tar.gz -zcf /usr/code/code.tar.gz .