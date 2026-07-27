add_library(Core
    App.cpp
    Window.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC Core)
