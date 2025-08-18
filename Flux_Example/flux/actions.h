#ifndef ACTIONS_H
#define ACTIONS_H

#include <QVariant>
#include "action.h"   // từ third_party/flux_qt

// Các loại action cho app
enum class ActionType {
    AddTask,         // payload: QString title
    ToggleTask,      // payload: int id
    RemoveTask,      // payload: int id
    ChangeFilter,    // payload: QString ("all"|"active"|"done")
    LoadStart,       // payload: (none)
    LoadSuccess,     // payload: QVariantList of {id:int, title:QString, done:bool}
    LoadFail         // payload: QString message
};

// Helper tạo Action nhanh
inline flux_qt::Action makeAction(ActionType t,
                                  QVariant payload = QVariant(),
                                  bool error = false)
{
    return flux_qt::Action(t, std::move(payload), error);
}

#endif // ACTIONS_H
