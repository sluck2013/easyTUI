#ifndef FACTORY_H
#define FACTORY_H

#include "Window.h"
#include "Style.h"
#include <memory>

namespace easyTUI {
    class Factory {
        public:
            virtual shared_ptr<Window> createWindow(
                    const unsigned x = 0, const unsigned y = 0,
                    const unsigned height = 0, const unsigned width = 0,  
                    Window::WinType winType = Window::WIN, 
                    shared_ptr<Window> pWParent = nullptr);
            virtual void setStyle(const Style& style); 
        private:
            Style style_;
    };
}

#endif
