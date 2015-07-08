#include "Panel.h"
#include <ncurses.h>
#include <thread>
#include <chrono>

using namespace std;

namespace easyTUI {
    void c_draw(shared_ptr<Panel> panel) {
        if (!panel) {
            //exception
            return;
        }
        panel->draw();
    }

    shared_ptr<Panel> Panel::panelPtr_ = nullptr;

    Panel::Panel() {
    }

    Panel::~Panel() {
        endwin();
        panelPtr_ = nullptr;
    }

    Panel& Panel::getInstance() {
        if (!panelPtr_) {
            panelPtr_ = shared_ptr<Panel>(new Panel());
        }
        return *panelPtr_;
    }

    void Panel::draw() {
        chrono::duration<double, milli> interval(refreshInterval_);
        while (true) {
            erase();
            refresh();
            auto it = windowList_.cbegin();
            for (; it != windowList_.cend(); ++it) {
                //lock
                (*it)->draw();
                //unlock
            }
            getch();

            if (refreshInterval_ > 0) {
                this_thread::sleep_for(interval);
            } else if (refreshInterval_ == 0) {
                continue;
            } else {
                break;
            }
        }
    }


    void Panel::run() {
        ////
        initscr(); 

        ColorManager &cm = ColorManager::getInstance();
        int colorIndex = cm.getColorIndex(style_.getForegroundColor(), style_.getBackgroundColor());
        bkgd(COLOR_PAIR(colorIndex));

        thread tDraw(c_draw, shared_ptr<Panel>(this));
        tDraw.join();
        /*
        initscr();
        start_color();
        WINDOW* a = newwin(10, 10, 10, 10);
        WINDOW* b = newwin(15, 15, 15, 15);
        init_pair(1, COLOR_GREEN, COLOR_WHITE);
        init_pair(2, COLOR_YELLOW, COLOR_CYAN);
        wbkgd(a, COLOR_PAIR(1));
        wbkgd(b, COLOR_PAIR(2));
        erase();
        refresh();
        werase(a);
        wrefresh(a);
        werase(b);
        wrefresh(b);
        getch();
        */
        ///
    }

    void Panel::addWindow(shared_ptr<Window> pWindow) {
        windowList_.push_back(pWindow);
    }

}
