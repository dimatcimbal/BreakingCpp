cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME EXEC_NAME)

set(INPUTREAD_LIB_TARGET InputCheckLib)

add_library(${INPUTREAD_LIB_TARGET} INTERFACE)
target_include_directories(${INPUTREAD_LIB_TARGET} INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

file(GLOB_RECURSE APP_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cxx
        ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cc
)

add_executable(${EXEC_NAME} ${APP_SOURCES})
target_link_libraries(${EXEC_NAME} PRIVATE
        FlightBookingLib
        ${INPUTREAD_LIB_TARGET}
)
