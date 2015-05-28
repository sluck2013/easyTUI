#ifndef STYLE_H
#define STYLE_H

#include "ColorManager.h"

namespace easyTUI {
    class Style {
        public:
            Style(ColorManager::Color bgColor = ColorManager::BLACK, 
                    ColorManager::Color fgColor = ColorManager::WHITE) :
                bgColor_(bgColor), fgColor_(fgColor) {};
            inline void setBackgroundColor(const ColorManager::Color color) {
                bgColor_ = color;
            };
            inline void setForegroundColor(const ColorManager::Color color) {
                fgColor_ = color;
            };
            inline ColorManager::Color getBackgroundColor() {
                return bgColor_;
            }
            inline ColorManager::Color getForegroundColor() {
                return fgColor_;
            }
        private:
            ColorManager::Color bgColor_, fgColor_;
    };
}

#endif
