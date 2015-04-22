#include "Window.h"

namespace easyTUI {
    Window::Window (const unsigned x, const unsigned y,
            const unsigned height, const unsigned width, const WinType winType,
            Window* pWParent) {
        switch (winType) {
            case WIN:
                _win = newwin(height, width, y, x);
                break;
            case SUBWIN:
                if (!pWParent) {
                    //exception
                }
                _win = subwin(pWParent->getRawWinPtr(), height, width, y, x);
                break;
            case DERWIN:
                if (!pWParent) {
                    //exception
                }
                _win = derwin(pWParent->getRawWinPtr(), height, width, y, x);
                break;
            default:
                //exception
                ;
        }
    }
    void Window::show() {

    }
}
