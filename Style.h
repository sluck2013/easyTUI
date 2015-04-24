#ifndef STYLE_H
#define STYLE_H

#include "ColorManager.h"

namespace easyTUI {
    class Style {
        public:
            Style(ColorManager::Color bgColor = ColorManager::BLACK, 
                    ColorManager::Color fgColor = ColorManager::WHITE) :
                _bgColor(bgColor), _fgColor(fgColor) {};
            inline void setBackgroundColor(const ColorManager::Color color) {
                _bgColor = color;
            };
            inline void setForegroundColor(const ColorManager::Color color) {
                _fgColor = color;
            };
            inline ColorManager::Color getBackgroundColor() {
                return _bgColor;
            }
            inline ColorManager::Color getForegroundColor() {
                return _fgColor;
            }
        protected:
            ColorManager::Color _bgColor, _fgColor;
    };
}

#endif
