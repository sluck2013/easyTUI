#include "WindowFactory.h"
#include "Panel.h"
#include "Style.h"
#include "ColorManager.h"
#include <vector>

using namespace easyTUI;

int main() {
    Panel &p = Panel::getInstance();
    p.setRefreshInterval(200);

    vector<ColorManager::Color> colors{
        ColorManager::BLACK,
        ColorManager::WHITE,
        ColorManager::RED,
        ColorManager::GREEN,
        ColorManager::BLUE,
        ColorManager::YELLOW,
        ColorManager::CYAN,
        ColorManager::MAGENTA
    };
    Style s;
    WindowFactory f;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            s.setBackgroundColor(colors[(i + j) % 8]);
            f.setStyle(s);
            p.addWindow(f.createWindow(i * 10, j * 10, 10, 10));
        }
    }

    p.run();
    return 0;
}
