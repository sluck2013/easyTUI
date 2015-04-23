#include "Panel.h"
#include <ncurses.h>

namespace easyTUI {
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

    void Panel::run() {
        initscr();
        addstr("hello");
        WINDOW* w = newwin(5, 5, 5, 5);
        start_color();
        init_pair(1, COLOR_WHITE, COLOR_BLUE);
        init_pair(2, COLOR_WHITE, COLOR_GREEN);
        WINDOW* w2 = newwin(10, 10, 10, 10);
        wbkgd(w, COLOR_PAIR(1));
        wbkgd(w2, COLOR_PAIR(2));
        refresh();
        wrefresh(w);
        wrefresh(w2);
        getch();
        delwin(w);
        touchwin(stdscr);
        refresh();
        
        getch();
    }

    void Panel::addWindow(Window& window) {
        __lstWindows.push_back(window);
    }

    unsigned Panel::__makeColorKey(const Style::Color fgColor, const Style::Color bgColor) const {
        unsigned k = 0x00;
        k &= (static_cast<unsigned>(fgColor) << 16);
        k &= static_cast<unsigned>(bgColor);
        return k;
    }
}
