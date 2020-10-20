#include <GL/glew.h>
#include "app/application.h"
#include "main_scene.h"

int main()
{
    Application app(1280, 720, "Simulator");
    MainScene mainScene;
    app.setScene(&mainScene);
    app.run();
}