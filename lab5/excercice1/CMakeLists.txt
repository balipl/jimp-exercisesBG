
project(excercice1)

set(HEDEAR_FILES Excercice1.h)
set(SOURCE_FILES Excercice1.cpp)

add_library(libexcercice1 STATIC ${SOURCE_FILES})
target_include_directories(libexcercice1 PUBLIC .)

add_executable(excercice1 ${SOURCE_FILES} main.cpp)

target_link_libraries(excercice1 libexcercice1)

