#include "drive.h"
#include "WindowFactory.h"
#include "Panel.h"

using namespace easyTUI;

int main() {
    Panel p = Panel::getInstance();
    p.run();
    
    Window w;
    return 0;
}
