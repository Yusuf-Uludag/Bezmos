add_executable(${PROJECT_NAME}
    Main.cpp
    CanvasLayer.cpp
    CanvasLayer.h
    MenuLayer.cpp
    MenuLayer.h
    Dot.h
)

# Connect Core and ImGui-SFML to your executable
target_link_libraries(${PROJECT_NAME} PRIVATE Core) # I excluded "ImGui-SFML"