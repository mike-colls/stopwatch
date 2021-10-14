add_library(stopwatch)

file(GLOB sources CONFIGURE_DEPENDS src/*.cpp)
target_sources(stopwatch PRIVATE ${sources})

file(GLOB headers CONFIGURE_DEPENDS include/stopwatch/*.hpp)
target_sources(stopwatch PRIVATE ${headers})

target_include_directories(stopwatch PUBLIC include)

target_compile_features(stopwatch PRIVATE cxx_std_20)

if(MSVC)
  target_compile_options(stopwatch PRIVATE /W4 /WX)
endif()
