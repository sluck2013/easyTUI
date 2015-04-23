#include "Factory.h"

namespace easyTUI {
    Window* Factory::createWindow(const unsigned x, const unsigned y,
            const unsigned height, const unsigned width, Window::WinType winType, Window* pWParent) {
        return new Window(x, y, height, width, winType, pWParent);
    }

    void Factory::setStyle(const Style& style) {
        _style = style;
    }
}
