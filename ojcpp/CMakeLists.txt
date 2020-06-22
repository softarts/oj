cmake_minimum_required(VERSION 3.5)
project(ojcpp)

set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if (LINUX)
    set(CXX_FLAGS
            -std=c++0x
        )
elseif(APPLE)
    set(CXX_FLAGS
        -std=c++1x
        )
    set(CMAKE_CXX_FLAGS_RELEASE "-O2 -finline-limit=1000 -DNDEBUG")
    set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
elseif(WIN32 )
    # good with clion and visual c++ 2015
    add_definitions(
            -D_WIN32_WINNT=0x0502
    )
    #add_compile_options(/wd4819)
endif()


#set(Boost_NO_SYSTEM_PATHS TRUE)
#
#if (Boost_NO_SYSTEM_PATHS)
#    if( WIN32 )
#        set(BOOST_ROOT "C:\\devtool\\boost_1_62")
#        set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib64-msvc-14.0")
#        set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/")
#    else()
#        #if (APPLE)
#        set(BOOST_ROOT "/Users/zhour/devtool/boost")
#        set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib")
#        set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/include")
#    endif()
#    message("use boost lib" ${BOOST_LIBRARY_DIRS}, ${BOOST_INCLUDE_DIRS})
#endif (Boost_NO_SYSTEM_PATHS)



include_directories(${PROJECT_SOURCE_DIR})
message("project path:" ${PROJECT_SOURCE_DIR})

# src files =======================================
file(GLOB_RECURSE LEETCODE "leetcode/*.cpp")
file(GLOB_RECURSE HHT "hht/*.cpp")
file(GLOB_RECURSE MAIN "codech/*.cpp")
file(GLOB_RECURSE COMPANY "company/*.cpp")
file(GLOB_RECURSE LINT "lintcode/*.cpp")
file(GLOB_RECURSE DESIGN "design/*.cpp")
file(GLOB_RECURSE CODILITY "ytilidoc/*.cpp")

set(SOURCE_FILES
        ${LEETCODE}
        ${MAIN}
        ${HHT}
        ${COMPANY}
        ${LINT}
        ${DESIGN}
        ${CODILITY}
        )

add_executable(ojcpp ${SOURCE_FILES})

