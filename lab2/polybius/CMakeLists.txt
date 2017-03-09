
project(polybius)

set(HEDEAR_FILES Polybius.h)
set(SOURCE_FILES Polybius.cpp)

add_library(libpolybius STATIC ${SOURCE_FILES} ../simpleforwardlist/SimpleForwardList.cpp ../simpleforwardlist/SimpleForwardList.h ../simpleforwardlist/main.cpp ../greatestproduct/GreatestProduct.cpp ../greatestproduct/GreatestProduct.h ../greatestproduct/main.cpp)
target_include_directories(libpolybius PUBLIC .)

add_executable(polybius ${SOURCE_FILES} main.cpp)

target_link_libraries(polybius libpolybius)

