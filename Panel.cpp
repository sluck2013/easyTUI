#include "Panel.h"
#include <ncurses.h>

namespace easyTUI {
    shared_ptr<Panel> Panel::_pPanel = nullptr;

    Panel::Panel() {
    }

    Panel::~Panel() {
        endwin();
        if (_pPanel) {
            delete _pPanel;
        }
        _pPanel = nullptr;
    }

    Panel& Panel::getInstance() {
        if (!_pPanel) {
            _pPanel = new Panel();
        }
        return *_pPanel;
    }

    void Panel::run() {
        initscr();
        addstr("hello");
        refresh();
        getch();
    }
}
