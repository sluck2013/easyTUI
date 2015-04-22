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
        refresh();
        getch();
    }
}
