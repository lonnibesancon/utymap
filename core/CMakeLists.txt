cmake_minimum_required (VERSION 3.1)
project ("UtyMap")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "/EHsc")

set(MAIN_SOURCE ${PROJECT_SOURCE_DIR}/src)
set(LIB_SOURCE ${PROJECT_SOURCE_DIR}/lib)
set(TEST_SOURCE ${PROJECT_SOURCE_DIR}/test)
set(SHARED_SOURCE ${PROJECT_SOURCE_DIR}/shared)


set(BOOST_ROOT C:/workspace/projects/libraries/boost_1_62_0)
set(BOOST_LIBRARYDIR ${BOOST_ROOT}/stage/lib)

set(PROTOBUF_INCLUDE_DIR C:/workspace/projects/libraries/protobuf-2.6.1/src)
set(Protobuf_SRC_ROOT_FOLDER C:/workspace/projects/libraries/protobuf-2.6.1/src)
set(PROTOBUF_LIBRARY C:/workspace/projects/libraries/protobuf-2.6.1/vsprojects/x64/Release/libprotobuf.lib)
set(PROTOBUF_PROTOC_EXECUTABLE C:/workspace/projects/libraries/protobuf-2.6.1/stage/protoc.exe)

set(ZLIB_INCLUDE_DIR C:/workspace/projects/libraries/zlib)
set(ZLIB_LIBRARY C:/workspace/projects/libraries/zlib/build/Debug/zlibd.lib)

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
