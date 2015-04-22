#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include "Window.h"
#include "Style.h"

namespace easyTUI {
    class WindowFactory {
        public:
            virtual Window create(
                    const unsigned x = 0, const unsigned y = 0,
                    const unsigned height = 0, const unsigned width = 0,  
                    Window::WinType winType = Window::WIN, Window* pWParent = nullptr);
            virtual void setStyle(Style& style) {};
    };
}

#endif
