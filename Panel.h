#ifndef PANEL_H
#define PANEL_H

#include <memory>
#include <list>
#include "Window.h"

namespace easyTUI {
    class Panel {
        public:
            ~Panel();
            static Panel& getInstance();
            void run();
            void addWindow(shared_ptr<Window> pWindow);
            inline void setRefreshInterval(const int itvl) {
                iRefreshItvl_ = itvl;
            }
            void draw();
        private:
            Panel();

            static shared_ptr<Panel> pPanel_;
            list<shared_ptr<Window>> lstWindows_;
            int iRefreshItvl_ = 0;
    };
}

#endif
