set(target "ApplicationServerQxServer")
if(NOT CMAKE_PROJECT_NAME)
project(${target} LANGUAGES CXX)
endif()

include(../QxOrm/QxOrm.cmake)
add_definitions(-DAPPLICATIONSERVERQXSERVER_LIBRARY)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins/server)
if(UNIX)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/plugins/server)
endif()

file(GLOB SRC
    "*.cpp"
)
file(GLOB HEADER
    "*.h"
    "*.hpp"
)
add_library(${target} SHARED ${SRC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
find_package(Qt5Core REQUIRED)
find_package(Qt5Xml REQUIRED)
if(${PACKAGE})
find_package(ApplicationServer)
find_package(ODataServer)
endif()
qt5_use_modules(${target} Core Xml)
target_include_directories(${target} PUBLIC
 PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${INCLUDE_FOLDER}>
)
if(COMMAND target_precompile_headers)
target_precompile_headers(${target}
 PUBLIC
  "ApplicationServerQxServer.Precompiled.h"
 )
 endif()
target_link_libraries(${target} ApplicationServerInterface QxOrm)
install(TARGETS ${target}
LIBRARY DESTINATION "${LIB_FOLDER}"
    ARCHIVE DESTINATION "${LIB_FOLDER}"
    RUNTIME DESTINATION "${PLUGIN_FOLDER}/server"
    INCLUDES DESTINATION "${INCLUDE_FOLDER}")
install(FILES ${HEADER} DESTINATION ${INCLUDE_FOLDER})
