#include "Panel.h"
#include <ncurses.h>
#include <thread>
#include <chrono>

using namespace std;

namespace easyTUI {
    void __draw__(shared_ptr<Panel> panel) {
        if (!panel) {
            //exception
            return;
        }
        panel->draw();
    }

    shared_ptr<Panel> Panel::__pPanel = nullptr;

    Panel::Panel() {
    }

    Panel::~Panel() {
        endwin();
        __pPanel = nullptr;
    }

    Panel& Panel::getInstance() {
        if (!__pPanel) {
            __pPanel = shared_ptr<Panel>(new Panel());
        }
        return *__pPanel;
    }

    void Panel::draw() {
        initscr();
        chrono::duration<double, milli> interval(__iRefreshItvl);
        while (true) {
            erase();
            refresh();
            auto it = __lstWindows.cbegin();
            for (; it != __lstWindows.cend(); ++it) {
                //lock
                (*it)->draw();
                //unlock
            }
            getch();

            if (__iRefreshItvl > 0) {
                this_thread::sleep_for(interval);
            } else if (__iRefreshItvl == 0) {
                continue;
            } else {
                break;
            }
        }
    }


    void Panel::run() {
        ////
        thread tDraw(__draw__, shared_ptr<Panel>(this));
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
        __lstWindows.push_back(pWindow);
    }

}
