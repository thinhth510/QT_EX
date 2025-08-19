#ifndef LOGGER_MIDDLEWARE_H
#define LOGGER_MIDDLEWARE_H

#include <QObject>
#include <QDebug>
#include "dispatcher.h"
#include "color_actions.h"

namespace flux {

// Simple observer that logs every dispatched action
class LoggerMiddleware : public QObject {
    Q_OBJECT
public:
    explicit LoggerMiddleware(Dispatcher* dispatcher, QObject* parent = nullptr)
        : QObject(parent) {
        connect(dispatcher, &Dispatcher::action, this, &LoggerMiddleware::onAction);
    }

private slots:
    void onAction(const flux::Action& a) {
        const char* name =
            a.type == ActionType::ToggleRed   ? "ToggleRed" :
            a.type == ActionType::ToggleGreen ? "ToggleGreen" :
            a.type == ActionType::ToggleBlue  ? "ToggleBlue" : "ResetAll";
        qDebug() << "[flux] action:" << name << "checked=" << a.checked;
    }
};

}

#endif // LOGGER_MIDDLEWARE_H
