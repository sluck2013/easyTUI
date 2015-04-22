#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

namespace easyTUI {
    class Window {
        public:
            enum WinType {WIN, SUBWIN, DERWIN};
            Window (const unsigned x = 0, const unsigned y = 0, 
                    const unsigned height = 0, const unsigned width = 0,
                    const WinType winType = WIN, Window* pWParent = nullptr);
            virtual void show();
        protected:
        private:
            Window *_pWinParent = nullptr;
            unsigned _x = 0, _y = 0, _height = 0, _width = 0;
            WinType _type = WIN;
    };
}
#endif
