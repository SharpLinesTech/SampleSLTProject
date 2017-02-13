cmake_minimum_required(VERSION 3.1)

project(slt_sample)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CONFIGURATION_TYPES Validate;Debug;Release CACHE TYPE INTERNAL FORCE)

set(CMAKE_CXX_FLAGS_VALIDATE ${CMAKE_CXX_FLAGS_DEBUG})
set(CMAKE_C_FLAGS_VALIDATE ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_C_FLAGS_VALIDATE ${CMAKE_C_FLAGS_DEBUG})
set(CMAKE_EXE_LINKER_FLAGS_VALIDATE ${CMAKE_EXE_LINKER_FLAGS_DEBUG})

if (MSVC)
  add_definitions(-DWIN32_LEAN_AND_MEAN)
  foreach (flag_var
               CMAKE_CXX_FLAGS 
               CMAKE_CXX_FLAGS_DEBUG 
               CMAKE_CXX_FLAGS_RELEASE
               CMAKE_CXX_FLAGS_VALIDATED
               CMAKE_C_FLAGS 
               CMAKE_C_FLAGS_DEBUG 
               CMAKE_C_FLAGS_RELEASE
               CMAKE_C_FLAGS_MINSIZEREL
               CMAKE_C_FLAGS_VALIDATE)
    string(REPLACE "/MD" "-MT" ${flag_var} "${${flag_var}}")
  endforeach()
endif()

SET(SLT_BUILT_DIR "" CACHE PATH "Location of the built slt toolset")

include_directories(${SLT_BUILT_DIR}/include src)

add_executable(slt_sample 
  src/main.cpp)

target_link_libraries(slt_sample ${SLT_BUILT_DIR}/lib/$<CONFIG>/slt_common.lib)