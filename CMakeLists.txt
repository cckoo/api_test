cmake_minimum_required(VERSION 3.9)
project(api_test)

set(CMAKE_CXX_STANDARD 11)

set(LIBRARIES
        gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cpp app/HttpRequest.cpp app/HttpRequest.h app/MyHttpRequest.cpp app/MyHttpRequest.h test/MyHttpRequestTest.cpp app/Url.cpp app/Url.h test/UrlTest.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBRARIES})