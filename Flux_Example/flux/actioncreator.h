#ifndef ACTIONCREATOR_H
#define ACTIONCREATOR_H

#include <QTimer>
#include "dispatcher.h"   // từ third_party/flux_qt
#include "actions.h"

struct ActionCreator {
    static void addTask(const QString &title) {
        if (title.trimmed().isEmpty()) return;
        flux_qt::Dispatcher::instance().dispatch(makeAction(ActionType::AddTask, title));
    }
    static void toggleTask(int id) {
        flux_qt::Dispatcher::instance().dispatch(makeAction(ActionType::ToggleTask, id));
    }
    static void removeTask(int id) {
        flux_qt::Dispatcher::instance().dispatch(makeAction(ActionType::RemoveTask, id));
    }
    static void changeFilter(const QString &f) {
        flux_qt::Dispatcher::instance().dispatch(makeAction(ActionType::ChangeFilter, f));
    }

    // Giả lập tải dữ liệu ban đầu
    static void loadInitial() {
        flux_qt::Dispatcher::instance().dispatch(makeAction(ActionType::LoadStart));
        QTimer::singleShot(600, []{
            QVariantList items;
            // mỗi item là QVariantMap {id, title, done}
            items << QVariantMap{{"id", 1}, {"title","Research QTNetwork"}, {"done", false}}
                  << QVariantMap{{"id", 2}, {"title","Research QThread"}, {"done", true}};
            flux_qt::Dispatcher::instance().dispatch(makeAction(ActionType::LoadSuccess, items));
        });
    }
};

#endif // ACTIONCREATOR_H
