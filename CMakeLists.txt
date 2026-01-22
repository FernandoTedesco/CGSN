cmake_minimum_required(VERSION 3.14)
project("CGSN")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 20)

set(SDL2_LIB "${CMAKE_SOURCE_DIR}/deps/SDL2/lib/x64/SDL2.lib")
set(SDL2_MAIN_LIB "${CMAKE_SOURCE_DIR}/deps/SDL2/lib/x64/SDL2main.lib")
set(SDL2_DLL "${CMAKE_SOURCE_DIR}/deps/SDL2/lib/x64/SDL2.dll")

add_executable(CGSN src/main.cpp)

target_include_directories(CGSN PRIVATE
${CMAKE_SOURCE_DIR}/src
${CMAKE_SOURCE_DIR}/deps/SDL2/include
)

target_link_libraries(CGSN PRIVATE
${SDL2_MAIN_LIB}
${SDL2_LIB}
shell32
)
add_custom_command(TARGET CGSN POST_BUILD
COMMAND ${CMAKE_COMMAND} -E copy_if_different
"${SDL2_DLL}"
$<TARGET_FILE_DIR:CGSN>
)