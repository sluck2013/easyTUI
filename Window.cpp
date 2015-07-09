#include "Window.h"
#include "ColorManager.h"
#include <sstream>

namespace easyTUI {
    Window::Window (const unsigned x, const unsigned y, const unsigned height, const unsigned width,
            const WinType winType, shared_ptr<Window> pWParent) : x_(x), y_(y), height_(height), width_(width),
        type_(winType), bgColor_(ColorManager::BLACK), fgColor_(ColorManager::WHITE) {
            switch(winType) {
                case WIN:
                    pWinParent_ = nullptr;
                    break;
                case SUBWIN:
                case DERWIN:
                    if (!pWParent) {
                        //exception
                    } else {
                        pWinParent_ = pWParent;
                    }
                default:
                    ;
            }
        }

    void Window::draw() {
        if (!rawWin_) {
            rawWin_ = newwin(height_, width_, y_, x_);
        }
        werase(rawWin_);
        ColorManager &cm = ColorManager::getInstance();
        //stringstream ss;
        //ss << cm.getColorIndex(fgColor_, bgColor_) << "(" << fgColor_ <<  bgColor_ <<")";
        wbkgd(rawWin_, COLOR_PAIR(cm.getColorIndex(fgColor_, bgColor_)));
        //waddstr(rawWin_, ss.str().c_str());
        for (auto &label : labelList_) {
            label.draw(*this);
        }
        wrefresh(rawWin_);
    }

    void Window::addLabel(const Label& label) {
        labelList_.push_back(label);
    }
}
