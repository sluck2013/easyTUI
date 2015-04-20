#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include "WindowInterface.h"

namespace easyTUI {
    class Window : public WindowInterface {
        public:
            virtual void show();
        private:
            unsigned int _x, _y, _height, _width;
            WINDOW* _win = nullptr;
    };
}
#endif
