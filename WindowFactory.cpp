#include "WindowFactory.h"

namespace easyTUI {
    Window WindowFactory::create(const unsigned x, const unsigned y,
            const unsigned height, const unsigned width, Window::WinType winType, Window* pWParent) {
        return Window(x, y, height, width, winType, pWParent);
    }
}
