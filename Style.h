#ifndef STYLE_H
#define STYLE_H

namespace easyTUI {
    class Style {
        public:
            enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE}
            Style() : _bgColor(BLACK), _fgColor(WHITE) {};
            void setBackgroundColor(const Color color = BLACK);
            void setForegroundColor(const Color color = WHITE);
        priavte:
            Color _bgColor, _fgColor;
    };
}

#endif
