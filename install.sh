
function basic_install(){
    apt install -y make gcc g++ build-essential git
}
function raylib_dependencies(){
    apt install -y libasound2-dev mesa-common-dev mesa-utils libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
}
function raylib_install(){
    git clone https://github.com/raysan5/raylib.git raylib
    cd raylib/src/
    make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED

    make install RAYLIB_LIBTYPE=SHARED
}

echo "Installing dependencies"
sleep 1000
basic_install()
raylib_dependencies()
sleep 1000
echo "Installing raylib"
raylib_install()
make -f Makefile
echo "Succesfully Installed"