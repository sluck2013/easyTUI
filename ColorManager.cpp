#include "ColorManager.h"

using namespace std;

namespace easyTUI {
    shared_ptr<ColorManager> ColorManager::this_ = nullptr;

    ColorManager& ColorManager::getInstance() {
        if (!this_) {
            this_ = shared_ptr<ColorManager>(new ColorManager());
        }
        return *this_;
    }
    
    int ColorManager::makeColorKey_(const Color fgColor, const Color bgColor) const {
        int k = 0x00000000;
        k |= (static_cast<int>(fgColor) << 4);
        k |= static_cast<int>(bgColor);
        return k;
    }

    int ColorManager::getColorIndex(const Color fgColor, const Color bgColor) {
        int key = makeColorKey_(fgColor, bgColor);
        if (mapColorPairs_.find(key) == mapColorPairs_.end()) {
            mapColorPairs_[key] = maxColorIndex_;
            init_pair(maxColorIndex_++, fgColor, bgColor);
        }
        return mapColorPairs_[key];
    }

    ColorManager::ColorManager() {
        if (hasColor_ = has_colors()) {
            start_color();
        }
    }

    ColorManager::~ColorManager() {
    }
}

//TODO::check _hasColor
