#ifndef FACTORY_H
#define FACTORY_H

#include "Window.h"
#include "Style.h"

namespace easyTUI {
    class Factory {
        public:
            virtual Window createWindow(
                    const unsigned x = 0, const unsigned y = 0,
                    const unsigned height = 0, const unsigned width = 0,  
                    Window::WinType winType = Window::WIN, Window* pWParent = nullptr);
            virtual void setStyle(const Style& style); 
        private:
            Style _style;
    };
}

#endif
