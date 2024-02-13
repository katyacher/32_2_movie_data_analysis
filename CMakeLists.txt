cmake_minimum_required(VERSION 3.5.0)
project(32_2_movie_data_analysis VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(32_2_movie_data_analysis main.cpp)

target_link_libraries(32_2_movie_data_analysis PRIVATE nlohmann_json::nlohmann_json)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
