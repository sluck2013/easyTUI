#ifndef LABEL_H
#define LABEL_H

#include <string>
#include "TextComponent.h"

using namespace std;

namespace easyTUI {
    class Label : public TextComponent {
        public:
            Label() = default;
            Label(const string& text) : text_(text) {};
            void setText(const string& text);
            string getText();
            void draw();
            void draw(Window& parentWindow);

            inline void setLeftAndTop(int left, int top) {
                left_ = left;
                top_ = top;
            }

            inline void setWidthAndHeight(int width, int height) {
                width_ = width;
                height_ = height;
            }
        private:
            WINDOW* getRawWindowPtr_(Window& window);
            string text_;
            int left_, top_, width_, height_;
    };
}

#endif
