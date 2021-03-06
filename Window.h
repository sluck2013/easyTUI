#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include "ColorManager.h"
#include "Label.h"
#include <list>

using namespace std;

namespace easyTUI {
    class Label;

    class Window {
        public:
            enum WinType {WIN, SUBWIN, DERWIN};
            Window (const unsigned x = 0, const unsigned y = 0, 
                    const unsigned height = 0, const unsigned width = 0,
                    const WinType winType = WIN, shared_ptr<Window> pWParent = nullptr);
            inline void setBackgroundColor(const ColorManager::Color color) {
                bgColor_ = color;
            };
            virtual void setForegroundColor(const ColorManager::Color color) {
                fgColor_ = color;
            };
            virtual void draw();
            void addLabel(const Label& label);
            inline WINDOW* getRawWindowPtr() {
                return rawWin_;
            }

        private:
            shared_ptr<Window> pWinParent_ = nullptr;
            unsigned x_ = 0, y_ = 0, height_ = 0, width_ = 0;
            ColorManager::Color bgColor_, fgColor_;
            WinType type_ = WIN;
            WINDOW* rawWin_ = nullptr;
            list<Label> labelList_;
    };
}
#endif
