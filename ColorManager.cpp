#include "ColorManager.h"

using namespace std;

namespace easyTUI {
    shared_ptr<ColorManager> ColorManager::__this = nullptr;

    ColorManager& ColorManager::getInstance() {
        if (!__this) {
            __this = shared_ptr<ColorManager>(new ColorManager());
        }
        return *__this;
    }
    
    int ColorManager::__makeColorKey(const Color fgColor, const Color bgColor) const {
        int k = 0x00000000;
        k |= (static_cast<int>(fgColor) << 4);
        k |= static_cast<int>(bgColor);
        return k;
    }

    int ColorManager::getColorIndex(const Color fgColor, const Color bgColor) {
        int key = __makeColorKey(fgColor, bgColor);
        if (__mapColorPairs.find(key) == __mapColorPairs.end()) {
            __mapColorPairs[key] = __iMaxColorIndex;
            init_pair(__iMaxColorIndex++, fgColor, bgColor);
        }
        return __mapColorPairs[key];
    }

    ColorManager::ColorManager() {
        if (__bHasColor = has_colors()) {
            start_color();
        }
    }

    ColorManager::~ColorManager() {
    }
}

//TODO::check _bHasColor
