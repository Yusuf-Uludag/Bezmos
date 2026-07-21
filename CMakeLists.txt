    cmake_minimum_required(VERSION 3.28)

    project(Bezmos VERSION 0.1 LANGUAGES CXX)

    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

    include(FetchContent)

    FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.1.0
        GIT_SHALLOW TRUE
        EXCLUDE_FROM_ALL
        SYSTEM)
    FetchContent_MakeAvailable(SFML)

    FetchContent_Declare(ImGUI
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG v1.91.9
        GIT_SHALLOW TRUE
        EXCLUDE_FROM_ALL
        SYSTEM)
    FetchContent_MakeAvailable(ImGUI)

    set(IMGUI_DIR ${imgui_SOURCE_DIR})

    set(IMGUI_SFML_FIND_SFML OFF)

    FetchContent_Declare(ImGUI-SFML
        GIT_REPOSITORY https://github.com/SFML/imgui-sfml.git
        GIT_TAG v3.0
        GIT_SHALLOW TRUE
        EXCLUDE_FROM_ALL
        SYSTEM)
    FetchContent_MakeAvailable(ImGUI-SFML)


    file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/App/*.cpp)

    add_executable(${PROJECT_NAME} ${SOURCES})

    target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
    target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics ImGui-SFML::ImGui-SFML)
    target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})


    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})