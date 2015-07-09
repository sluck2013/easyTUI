#ifndef TEXTCOMPONENT_H
#define TEXTCOMPONENT_H

#include "Window.h"

using namespace std;

namespace easyTUI {
    class Window;
    class TextComponent {
        public:
            virtual void setText(const string& s) = 0;
            virtual string getText() = 0;
            virtual void draw() = 0;
            virtual void draw(Window& parentWindow) = 0;
    };
}

#endif
