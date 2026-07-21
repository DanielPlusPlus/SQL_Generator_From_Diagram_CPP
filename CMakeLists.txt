cmake_minimum_required(VERSION 3.16)

project(SQLModeler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(EXTERNAL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/external")

set(Qt6_DIR "${EXTERNAL_DIR}/Qt-6.11.1/lib/cmake/Qt6")
set(CMAKE_PREFIX_PATH "${EXTERNAL_DIR}/Qt-6.11.1")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(ORACLE_LIB_DIR "${EXTERNAL_DIR}/oracle/lib")
set(ORACLE_INC_DIR "${EXTERNAL_DIR}/oracle/include")
set(MYSQL_DIR "${EXTERNAL_DIR}/mysql")
set(NANODBC_DIR "${EXTERNAL_DIR}/nanodbc")
set(PG_DIR "${EXTERNAL_DIR}/pgsql")
set(PQXX_DIR "${EXTERNAL_DIR}/libpqxx")

file(GLOB_RECURSE SOURCES
    src/*.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    src/main.cpp
    src/MainWindow.cpp
    include/MainWindow.hpp
    src/views/MainWindowView.cpp
    include/views/MainWindowView.hpp
    src/views/ToolBarView.cpp
    include/views/ToolBarView.hpp
    include/views/MenuBarView.hpp
    src/views/MenuBarView.cpp
    include/views/ScrollAreaView.hpp
    src/views/ScrollAreaView.cpp
    include/controllers/MainWindowController.hpp
    src/controllers/MainWindowController.cpp
    include/views/ConfirmationDialogView.hpp
    src/views/ConfirmationDialogView.cpp
)

# set_target_properties(${PROJECT_NAME} PROPERTIES
#     WIN32_EXECUTABLE TRUE
# )

target_compile_definitions(${PROJECT_NAME} PRIVATE
    STATIC_CONCPP
    NANODBC_ENABLE_UNICODE
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)


target_link_libraries(${PROJECT_NAME} PRIVATE
    "${ORACLE_LIB_DIR}/oci.lib"
    "$<$<CONFIG:Debug>:${ORACLE_LIB_DIR}/oraocci23d.lib>"
    "$<$<NOT:$<CONFIG:Debug>>:${ORACLE_LIB_DIR}/oraocci23.lib>"
)


target_link_libraries(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Debug>:
        "${MYSQL_DIR}/lib64/debug/vs14/mysqlcppconnx-static.lib"
        "${MYSQL_DIR}/lib64/debug/vs14/mysqlcppconn-static.lib"
    >
    $<$<NOT:$<CONFIG:Debug>>:
        "${MYSQL_DIR}/lib64/vs14/mysqlcppconnx-static.lib"
        "${MYSQL_DIR}/lib64/vs14/mysqlcppconn-static.lib"
    >

    "${MYSQL_DIR}/lib64/vs14/libcrypto.lib"
    "${MYSQL_DIR}/lib64/vs14/libssl.lib"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    "${PG_DIR}/lib/pqxx.lib"
    "${PG_DIR}/lib/libpq.lib"
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    odbc32.lib
    ws2_32.lib
    secur32.lib
    crypt32.lib
    advapi32.lib
    shell32.lib
    dnsapi.lib
)

file(GLOB ALL_PG_DLLS "${PG_DIR}/bin/*.dll")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${EXTERNAL_DIR}/oracle/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${MYSQL_DIR}/bin"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${MYSQL_DIR}/lib64"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${ALL_PG_DLLS}
        $<TARGET_FILE_DIR:${PROJECT_NAME}>

    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/icons"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/icons

    COMMAND "${EXTERNAL_DIR}/Qt-6.11.1/bin/windeployqt.exe"
        $<$<CONFIG:Debug>:--debug>
        $<$<NOT:$<CONFIG:Debug>>:--release>
        --compiler-runtime
        $<TARGET_FILE:${PROJECT_NAME}>
)