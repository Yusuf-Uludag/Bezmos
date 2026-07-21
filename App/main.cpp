#include "Core/App.h"

int main()
{
    Core::AppConfig appSpec;
    appSpec.name = "Cengaver";
    appSpec.windowSpec.width = 1280;
    appSpec.windowSpec.height = 720;

    Core::App app(appSpec);

    app.Run();
}