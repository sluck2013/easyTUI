#ifndef PANEL_H
#define PANEL_H

#include <memory>

using namespace std;

namespace easyTUI {
    class Panel {
        public:
            ~Panel();
            static Panel& getInstance();
            void run();
        private:
            Panel();
            static shared_ptr<Panel> _pPanel;
    };
}

#endif
