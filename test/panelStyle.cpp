#include "Panel.h"
#include "Style.h"

using namespace easyTUI;

int main() {
    Panel &p = Panel::getInstance();
    p.setRefreshInterval(200);

    Style s;
    s.setBackgroundColor(ColorManager::RED);
    s.setForegroundColor(ColorManager::GREEN);
    p.setStyle(s);

    p.run();
    return 0;
}
