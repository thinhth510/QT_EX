#ifndef COLORSTORE_H
#define COLORSTORE_H

#include <QObject>
#include <QMap>
#include <QString>
#include "color_actions.h"


namespace flux {


    class ColorStore : public QObject {
        Q_OBJECT
    public:
        explicit ColorStore(QObject* parent = nullptr);


        const RGBState& state() const;


    public slots:
        void onAction(const flux::Action& a);


    signals:
        void stateChanged(const flux::RGBState& state);


    private:
        RGBState m_state{};
        void recompute();
    };


}
#endif // COLORSTORE_H
