#include "Factory.h"

namespace easyTUI {
    shared_ptr<Window> Factory::createWindow(const unsigned x, const unsigned y,
            const unsigned height, const unsigned width, Window::WinType winType, 
            shared_ptr<Window> pWParent) {
        auto pWin = shared_ptr<Window> (
                new Window(x, y, height, width, winType, pWParent));
        pWin->setBackgroundColor(_style.getBackgroundColor());
        pWin->setForegroundColor(_style.getForegroundColor());
        return pWin;
    }

    void Factory::setStyle(const Style& style) {
        _style = style;
    }
}
