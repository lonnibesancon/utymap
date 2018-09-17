cmake_minimum_required (VERSION 3.1)
project ("UtyMap")

set(CMAKE_CXX_STANDARD 11)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(CMAKE_CXX_FLAGS "/EHsc")
endif()

set(MAIN_SOURCE ${PROJECT_SOURCE_DIR}/src)
set(LIB_SOURCE ${PROJECT_SOURCE_DIR}/lib)
set(TEST_SOURCE ${PROJECT_SOURCE_DIR}/test)
set(SHARED_SOURCE ${PROJECT_SOURCE_DIR}/shared)



# initialize boost
find_package(Boost REQUIRED)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
    add_definitions("-DHAS_BOOST")
	# add_definitions("-DBOOST_NO_EXCEPTIONS")
ENDIF()

#initialize protobuf package
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIR})

#initialize zlib
find_package(ZLIB REQUIRED)
include_directories(${ZLIB_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(shared)
