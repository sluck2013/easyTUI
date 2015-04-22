#include "Style.h"

namespace easyTUI {
    void Style::setBackgroundColor(const Color color) {
        _bgColor = color;
    }

    void Style::setForegroundColor(const Color color) {
        _fgColor = color;
    } 
}
