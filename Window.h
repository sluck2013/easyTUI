#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include "Style.h"

namespace easyTUI {
    class Window {
        public:
            enum WinType {WIN, SUBWIN, DERWIN};
            Window (const unsigned x = 0, const unsigned y = 0, 
                    const unsigned height = 0, const unsigned width = 0,
                    const WinType winType = WIN, Window* pWParent = nullptr);
            inline void setBackgroundColor(const Style::Color color) {
                _bgColor = color;
            };
            virtual void setForegroundColor(const Style::Color color) {
                _fgColor = color;
            };

        protected:
            Window *_pWinParent = nullptr;
            unsigned _x = 0, _y = 0, _height = 0, _width = 0;
            Style::Color _bgColor, _fgColor;
            
        private:
            WinType __type = WIN;
    };
}
#endif
