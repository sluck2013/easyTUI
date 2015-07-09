#include "WindowFactory.h"
#include "Panel.h"
#include "Style.h"
#include "ColorManager.h"


using namespace easyTUI;

int main() {
    Panel &p = Panel::getInstance();
    p.setRefreshInterval(200);

    Style s(ColorManager::YELLOW);
    WindowFactory f;
    f.setStyle(s);
    p.addWindow(f.createWindow(10, 10, 10, 10));
    s.setBackgroundColor(ColorManager::CYAN);
    f.setStyle(s);
    p.addWindow(f.createWindow(15, 15, 15, 15));

    p.run();
    return 0;
}
