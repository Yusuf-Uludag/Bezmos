add_library(Core
    App.cpp
    App.h
    Window.cpp
    Window.h
    Layer.h
)

target_link_libraries(${PROJECT_NAME} PUBLIC Core)
