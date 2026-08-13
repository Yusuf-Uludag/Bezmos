add_library(Core
    App.cpp
    App.h
    Window.cpp
    Window.h
    Layer.h
)

# Tell CMake where to find headers (so App.h and Window.h see each other)
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link SFML libraries AND ImGui-SFML to Core
target_link_libraries(Core PUBLIC 
    SFML::Graphics 
    SFML::Window 
    SFML::System 
    ImGui-SFML
)