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

    shared_ptr<Panel> Panel::pPanel_ = nullptr;

    Panel::Panel() {
    }

    Panel::~Panel() {
        endwin();
        pPanel_ = nullptr;
    }

    Panel& Panel::getInstance() {
        if (!pPanel_) {
            pPanel_ = shared_ptr<Panel>(new Panel());
        }
        return *pPanel_;
    }

    void Panel::draw() {
        initscr();
        chrono::duration<double, milli> interval(iRefreshItvl_);
        while (true) {
            erase();
            refresh();
            auto it = lstWindows_.cbegin();
            for (; it != lstWindows_.cend(); ++it) {
                //lock
                (*it)->draw();
                //unlock
            }
            getch();

            if (iRefreshItvl_ > 0) {
                this_thread::sleep_for(interval);
            } else if (iRefreshItvl_ == 0) {
                continue;
            } else {
                break;
            }
        }
    }


    void Panel::run() {
        ////
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
        lstWindows_.push_back(pWindow);
    }

}
