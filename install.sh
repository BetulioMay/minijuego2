#!bin/bash

basic_install(){
    apt install -y make gcc g++ build-essential git
}
raylib_dependencies(){
    apt install -y libasound2-dev mesa-common-dev mesa-utils libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
}
raylib_install(){
    git clone https://github.com/raysan5/raylib.git raylib
    cd raylib/src/
    make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED

    make install RAYLIB_LIBTYPE=SHARED
}
createDirectories(){
    if [ ! -d bin ]; then mkdir bin; fi
    if [ ! -d obj ]; then mkdir obj; fi
    if [ ! -d lib ]; then mkdir lib; fi
}

echo "Installing dependencies..."
sleep 1
basic_install
raylib_dependencies

echo "Installing raylib..."
sleep 1
raylib_install

echo "Creating directories..."
sleep 1
createDirectories

echo "Building..."
make -f Makefile
echo "Succesfully Installed"