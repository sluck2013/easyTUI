#ifndef STYLE_H
#define STYLE_H

namespace easyTUI {
    class Style {
        public:
            enum Color {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
            Style() : _bgColor(BLACK), _fgColor(WHITE) {};
            inline void setBackgroundColor(const Color color) {
                _bgColor = color;
            };
            inline void setForegroundColor(const Color color) {
                _fgColor = color;
            };
            inline Color getBackgroundColor() {
                return _bgColor;
            }
            inline Color getForegroundColor() {
                return _fgColor;
            }
        protected:
            Color _bgColor, _fgColor;
    };
}

#endif
