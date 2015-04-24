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
                __iRefreshItvl = itvl;
            }
            void draw();
        private:
            Panel();

            static shared_ptr<Panel> __pPanel;
            list<shared_ptr<Window>> __lstWindows;
            int __iRefreshItvl = 0;
    };
}

#endif
