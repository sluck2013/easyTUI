#ifndef PANEL_H
#define PANEL_H

#include <memory>
#include <list>
#include "Window.h"
#include "Style.h"
#include <unordered_map>

using namespace std;

namespace easyTUI {
    class Panel {
        public:
            ~Panel();
            static Panel& getInstance();
            void run();
            void addWindow(Window *pWindow);
        private:
            Panel();
            unsigned  __makeColorKey(const Style::Color fgColor, const Style::Color bgColor) const;
            int __getColorIndex(const Style::Color fgColor, const Style::Color bgColor);

            static shared_ptr<Panel> __pPanel;
            list<Window*> __lstWindows;
            unordered_map<unsigned, int> __mapColorPairs;
            int __iMaxColorIndex = 0;           
    };
}

#endif
