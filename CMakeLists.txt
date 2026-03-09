cmake_minimum_required(VERSION 3.24)
project(midas-backend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(shared-contracts)
add_subdirectory(audio-engine)
add_subdirectory(mixer-engine)
add_subdirectory(midas-core)

add_custom_target(backend-compile-check
    DEPENDS
        shared-contracts-compile-check
        audio-engine-compile-check
        mixer-engine-compile-check
        midas-core-compile-check
)
