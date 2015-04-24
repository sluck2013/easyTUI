#ifndef COLORMANAGER_H
#define COLORMANAGER_H

#include <unordered_map>
#include <memory>
#include <ncurses.h>

using namespace std;

namespace easyTUI {
    class ColorManager {
        public:
            enum Color {BLACK = COLOR_BLACK, RED = COLOR_RED, 
                GREEN = COLOR_GREEN, YELLOW = COLOR_YELLOW, 
                BLUE = COLOR_BLUE, MAGENTA = COLOR_MAGENTA, 
                CYAN = COLOR_CYAN, WHITE = COLOR_WHITE};
            static ColorManager& getInstance();
            int getColorIndex(const Color fgColor, const Color bgColor);
            ~ColorManager();
        private:
            unordered_map<int, int> __mapColorPairs;
            int __iMaxColorIndex = 1;
            static shared_ptr<ColorManager> __this;
            bool __bHasColor = false;

            ColorManager();
            int  __makeColorKey(const Color fgColor, const Color bgColor) const;
    };
}

#endif
