#include "color_store.h"


namespace flux {


ColorStore::ColorStore(QObject* parent) : QObject(parent) {}


const RGBState& ColorStore::state() const {
    return m_state;
}


void ColorStore::onAction(const flux::Action& a) {
    switch (a.type) {
        case ActionType::ToggleRed: m_state.red = a.checked; break;
        case ActionType::ToggleGreen: m_state.green = a.checked; break;
        case ActionType::ToggleBlue: m_state.blue = a.checked; break;
        case ActionType::ResetAll: m_state = {}; break;
    }
    recompute();
    emit stateChanged(m_state);
}


void ColorStore::recompute() {
    const int bits = (m_state.red ? 4 : 0) | (m_state.green ? 2 : 0) | (m_state.blue ? 1 : 0);
    static const QMap<int,int> pageMap{{0,0},{1,3},{2,2},{3,6},{4,1},{5,5},{6,4},{7,7}};
    static const QMap<int, QString> nameMap{{0,"home"},{1,"blue"},{2,"green"},{3,"cyan"},{4,"red"},{5,"magenta"},{6,"yellow"},{7,"white"}};
    m_state.pageIndex = pageMap.value(bits,0);
    m_state.pageName = nameMap.value(bits, "home");
}


}
