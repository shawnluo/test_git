#!/usr/bin/bash
set -e
# env
# m shawn_test 

android_path="/home/shawn/starship/FERN/AOSP_FERN/vendor/LA.VENDOR.14.3.4.r1/LINUX/android"
xrservice_path="/home/shawn/starship/FERN/AOSP_FERN/vendor/LA.VENDOR.14.3.4.r1/LINUX/android/vendor/thundercomm/xrservice_demo"

out_path="out/target/product/anorak/vendor/bin"

shawn_test_path=${android_path}/${out_path}
echo $shawn_test_path

adb push ${shawn_test_path}/shawn_test /vendor/bin




if [ "$1" == "pull" ]; then
	adb pull /data/vendor/xlogger ${xrservice_path}
else
	adb shell "rm /data/vendor/xlogger/*"
fi



# adb shell shawn_test
