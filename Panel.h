#ifndef PANEL_H
#define PANEL_H

#include <memory>
#include <list>
#include "Window.h"
#include "Style.h"

namespace easyTUI {
    class Panel {
        public:
            ~Panel();
            static Panel& getInstance();
            void run();
            void addWindow(shared_ptr<Window> pWindow);
            inline void setRefreshInterval(const int interval) {
                refreshInterval_ = interval;
            }
            inline void setStyle(const Style& style) {
                style_ = style;
            }
            void draw();
        private:
            Panel();

            static shared_ptr<Panel> panelPtr_;
            list<shared_ptr<Window>> windowList_;
            int refreshInterval_ = 0;
            Style style_;
    };
}

#endif
