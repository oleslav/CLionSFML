#include "Engine/Engine.h"

int main()
{
    Engine *engine = Engine::Instance();
    (*engine).start();
    return 0;
}