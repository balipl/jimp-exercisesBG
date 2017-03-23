
project(array2d)

set(HEDEAR_FILES Array2d.h)
set(SOURCE_FILES Array2d.cpp)

add_library(libarray2d STATIC ${SOURCE_FILES})
target_include_directories(libarray2d PUBLIC .)

add_executable(array2d ${SOURCE_FILES} main.cpp ../xorcypherbreaker/XorCypherBreaker.cpp ../xorcypherbreaker/XorCypherBreaker.h ../xorcypherbreaker/main.cpp ../xorcypherbreaker/XorCypherBreaker.cpp ../xorcypherbreaker/XorCypherBreaker.h ../xorcypherbreaker/main.cpp)

target_link_libraries(array2d libarray2d)

