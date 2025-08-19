#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>
#include "color_actions.h"


namespace flux {


    // Minimal Dispatcher: broadcast-only; middlewares can also listen to `action`.
    class Dispatcher : public QObject {
        Q_OBJECT
    public:
        explicit Dispatcher(QObject* parent = nullptr) : QObject(parent) {}


        void dispatch(const Action& a) { emit action(a); }


    signals:
        void action(const flux::Action& a);
    };


}

#endif // DISPATCHER_H
