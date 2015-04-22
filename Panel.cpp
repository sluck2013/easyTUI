#include "Panel.h"
#include <ncurses.h>

namespace easyTUI {
    shared_ptr<Panel> Panel::_pPanel = nullptr;

    Panel::Panel() {
    }

    Panel::~Panel() {
        endwin();
        _pPanel = nullptr;
    }

    Panel& Panel::getInstance() {
        if (!_pPanel) {
            _pPanel = shared_ptr<Panel>(new Panel());
        }
        return *_pPanel;
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
        getch();
    }
}
