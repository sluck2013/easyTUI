#include "Label.h"
#include <ncurses.h>

namespace easyTUI {
    void Label::setText(const string& text) {
        text_ = text;
    }

    string Label::getText() {
        return text_;
    }

    void Label::draw() {
        mvaddstr(top_, left_, text_.c_str());
    }

    void Label::draw(Window& parentWindow) {
        WINDOW* parentRawWin = parentWindow.getRawWindowPtr();
        mvwaddstr(parentRawWin, 1, 1, text_.c_str());
        //mvwaddstr(parentRawWin, top_, left_, text_.c_str());
    }
}
