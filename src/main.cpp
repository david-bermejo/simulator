#include "app/application.h"
#include "main_scene.h"

int main()
{
    Application app(1920, 1080, "Simulator");
    MainScene mainScene;
    app.setScene(&mainScene);
    app.run();
}