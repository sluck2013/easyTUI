#include "Window.h"

namespace easyTUI {
    Window::Window (const unsigned x, const unsigned y, 
            const unsigned height, const unsigned width,
            const WinType winType, Window* pWParent) : 
        _x(x), _y(y), _height(height), _width(width) {
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
    };
    void Window::show() {

    }
}
