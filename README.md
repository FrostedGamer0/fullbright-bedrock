
# FULLBRIGHT Bedrock

An open-sourced dll for Minecraft Bedrock edition that let's you basically have infinite night vision. 


## FAQ

#### Is the brightness adjustable?

It is adjustable in the source code, change the brightness value and build the DLL yourself.

#### Is it up-to-date?

I will try my best to keep it up-to-date for every minecraft version.

#### Was AI used?

Yes I have used AI to write the code for this project because I have no idea how C++ works. Currently learning tho.


## Installation

    Getting project files:
        git clone https://github.com/FrostedGamer0/fullbright-bedrock
    
    Building the project:
        cmake -B build -S . -DCMAKE_BUILD_TYPE=Release -A x64
        cmake --build build --config Release

## Prerequisites
    1. Visual Studio 2022 (Community Edition is fine) or MSVC Build Tools.
    2. CMake (Version 3.16 or higher).
    3. Git (For cloning the repository).
