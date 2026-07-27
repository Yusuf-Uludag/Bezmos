#include "CanvasLayer.h"
#include "Core/App.h"
#include "MenuLayer.h"
#include <memory>

int main()
{
    Core::AppConfig appSpec;
    appSpec.name = "Cengaver";
    appSpec.windowSpec.width = 1280;
    appSpec.windowSpec.height = 720;

    Core::App app(appSpec);

    CanvasLayer canvasLayer;
    MenuLayer menuLayer;

    app.PushLayer(std::make_unique<CanvasLayer>(canvasLayer));

    app.Run();
}