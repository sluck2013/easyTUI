#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include "Window.h"
#include <memory>
#include "Factory.h"

namespace easyTUI {
    class WindowFactory {
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
