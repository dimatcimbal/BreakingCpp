cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME EXEC_NAME)

set(FLIGHTBOOKING_LIB_TARGET FlightBookingLib)

# the lib sources glob
file(GLOB_RECURSE FLIGHTBOOKING_LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
)

# Create a shared FlightBookingLib
add_library(${FLIGHTBOOKING_LIB_TARGET}
        ${FLIGHTBOOKING_LIB_SOURCES}
)
target_include_directories(${FLIGHTBOOKING_LIB_TARGET} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# the private sources glob
file(GLOB_RECURSE FLIGHTBOOKING_APP_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cxx
        ${CMAKE_CURRENT_SOURCE_DIR}/app/*.cc
)

# Create an executable
add_executable(${EXEC_NAME} ${FLIGHTBOOKING_APP_SOURCES})
target_link_libraries(${EXEC_NAME} PRIVATE
        ${FLIGHTBOOKING_LIB_TARGET}
)
