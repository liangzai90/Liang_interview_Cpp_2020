rm -rf build 
mkdir build && cd build

cmake ../

make -j4
echo "rebuild done"
