#!/bin/bash
echo Starting Build...
cd "$(dirname "$0")"
rm -rf build
mkdir build
cp -r assets build/
clang++ $(find source -name '*.cpp') -framework AudioToolbox -framework CoreFoundation -std=c++20 -arch x86_64 -arch arm64 -o build/Hacknet
echo "Done."
read -p "Press Enter to Run Application."
./build/Hacknet