#ifndef WINDOWFACTORY_H
#define WINDOWFACTORY_H

#include <ncurses.h>

namespace easyTUI {
    class WindowFactory {
        enum WinType {WINDOW, SUBWINDOW};
        WINDOW* createWin(WinType winType);
        virtual Window create() {};
    }
}

#endif
