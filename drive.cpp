#include "drive.h"
#include "Factory.h"
#include "Panel.h"

using namespace easyTUI;

int main() {
    Panel p = Panel::getInstance();
    p.setRefreshInterval(1000);
    p.run();
    
    Window w;
    return 0;
}
