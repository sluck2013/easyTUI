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
            inline WINDOW* getRawWinPtr() { return _win; };
        private:
            WINDOW* _win = nullptr;
    };
}
#endif
