#include "Window.h"
#include "ColorManager.h"
#include <sstream>

namespace easyTUI {
    Window::Window (const unsigned x, const unsigned y, 
            const unsigned height, const unsigned width,
            const WinType winType, shared_ptr<Window> pWParent) : 
        _x(x), _y(y), _height(height), _width(width),
        __type(winType), _bgColor(ColorManager::BLACK), 
        _fgColor(ColorManager::WHITE) {
            switch(winType) {
                case WIN:
                    _pWinParent = nullptr;
                    break;
                case SUBWIN:
                case DERWIN:
                    if (!pWParent) {
                        //exception
                    } else {
                        _pWinParent = pWParent;
                    }
                default:
                    ;
            }
        }

    void Window::draw() {
        if (!__rawWin) {
            __rawWin = newwin(_height, _width, _y, _x);
        }
        werase(__rawWin);
        ColorManager &cm = ColorManager::getInstance();
        stringstream ss;
        ss << cm.getColorIndex(_fgColor, _bgColor) << "(" << _fgColor <<  _bgColor <<")";
        wbkgd(__rawWin, COLOR_PAIR(cm.getColorIndex(_fgColor, _bgColor)));
        waddstr(__rawWin, ss.str().c_str());
        wrefresh(__rawWin);
    }
}
