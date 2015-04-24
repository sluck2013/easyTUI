#include "Panel.h"
#include <ncurses.h>
#include <thread>
#include <chrono>

namespace easyTUI {
    void __draw__(Panel *panel) {
        if (!panel) {
            //exception
            return;
        }
        panel->draw();
    }

    shared_ptr<Panel> Panel::__pPanel = nullptr;

    Panel::Panel() {
    }

    Panel::~Panel() {
        endwin();
        __pPanel = nullptr;
    }

    Panel& Panel::getInstance() {
        if (!__pPanel) {
            __pPanel = shared_ptr<Panel>(new Panel());
        }
        return *__pPanel;
    }

    void Panel::draw() {
        chrono::duration<double, milli> interval(__iRefreshItvl);
        while (true) {
            addstr("thread work\n");
            touchwin(stdscr);
            refresh();
            if (__iRefreshItvl > 0) {
                this_thread::sleep_for(interval);
            }
        }
    }


    void Panel::run() {
        initscr();
////
        thread tDraw(__draw__, this);
        tDraw.join();
///
        
        getch();
    }

    void Panel::addWindow(Window* pWindow) {
        __lstWindows.push_back(pWindow);
    }

    unsigned Panel::__makeColorKey(const Style::Color fgColor, const Style::Color bgColor) const {
        unsigned k = 0x00;
        k &= (static_cast<unsigned>(fgColor) << 16);
        k &= static_cast<unsigned>(bgColor);
        return k;
    }

    int Panel::__getColorIndex(const Style::Color fgColor, const Style::Color bgColor) {
        unsigned key = __makeColorKey(fgColor, bgColor);
        if (__mapColorPairs.find(key) == __mapColorPairs.end()) {
            __mapColorPairs[key] = __iMaxColorIndex++;
        }
        return __mapColorPairs[key];
    }
}
