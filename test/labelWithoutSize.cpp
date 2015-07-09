#include "Label.h"
#include "ColorManager.h"
#include "Style.h"
#include "Panel.h"
#include "WindowFactory.h"

using namespace easyTUI;
using namespace std;

int main() {
    Panel &p = Panel::getInstance();
    p.setRefreshInterval(200);

    Style s;
    s.setBackgroundColor(ColorManager::CYAN);
    WindowFactory f;
    f.setStyle(s);
    auto w = f.createWindow(5, 5, 20, 20);
    Label l;
    l.setText("hello");
    w->addLabel(l);
    p.addWindow(w);

    p.run();

}
