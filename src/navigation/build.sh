#!/bin/bash

clean=0
capi=0

function check_path_for_capi
{
	if [ ! $COMMONAPI_TOOL_DIR ]
	then 
		echo 'Set the dir of the common api tools'
		echo 'export COMMONAPI_TOOL_DIR=<path>'
		exit 1
	fi

	if [ ! $COMMONAPI_DBUS_TOOL_DIR ]
	then 
		echo 'Set the dir of the common api dbus tools'
		echo 'export COMMONAPI_DBUS_TOOL_DIR=<path>'
		exit 1
	fi

	if [ ! $DBUS_LIB_PATH ]
	then 
		echo 'Set the dir of the patched dbus'
		echo 'export DBUS_LIB_PATH=<path>'
		exit 1
	fi
}
 
while getopts cm opt
do
	case $opt in
	c)
		clean=1
		;;
	m)
		capi=1
		;;
	\?)
		echo "Usage:"
		echo "$0 [-c] [-m]"
		echo "-c: build with clean"
		echo "-m: build with commonAPI plugins "
		exit 1
	esac
done

if [ "$capi" = 1 ]
then
	check_path_for_capi
fi

if [ "$clean" = 1 ]
then
	echo 'clean up the build folder'
	if [ -d "./build" ]
	then
		find ./build ! -name '*.cbp' -type f -exec rm -f {} +
	fi
fi

mkdir -p build
cd build
mkdir -p navit
cd navit
echo 'build navit'
if [ "$clean" = 1 ]
then
	cmake -DDISABLE_QT=1 -DSAMPLE_MAP=0 -Dvehicle/null=1 -Dgraphics/qt_qpainter=0 ../../navit/
fi
make
cd ../
echo 'build navigation'
if [ "$clean" = 1 ]
then
	if [ "$capi" = 0 ]
	then
		cmake -DWITH_PLUGIN_MIGRATION=0 ../
	else
		cmake -DWITH_PLUGIN_MIGRATION=1 -DDBUS_LIB_PATH=$DBUS_LIB_PATH -DCOMMONAPI_TOOL_DIR=$COMMONAPI_TOOL_DIR -DCOMMONAPI_DBUS_TOOL_DIR=$COMMONAPI_DBUS_TOOL_DIR ../
	fi
fi
make
cd ..


