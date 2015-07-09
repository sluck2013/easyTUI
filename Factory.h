#ifndef FACTORY_H
#define FACTORY_H
#include "Style.h"

namespace easyTUI {
    class Factory {
        public:
            Factory() {}
            virtual void setStyle(const Style& style);
            ~Factory() {}
        private:
            int i;
    };
}

#endif
