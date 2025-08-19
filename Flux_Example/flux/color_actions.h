#ifndef COLOR_ACTIONS_H
#define COLOR_ACTIONS_H

#include <QString>


namespace flux {


    // Action types for RGB toggles
    enum class ActionType {
        ToggleRed,
        ToggleGreen,
        ToggleBlue,
        ResetAll
    };


    struct Action {
        ActionType type{};
        bool checked{}; // payload for Toggle*; ignored by ResetAll
    };


    // App state carried by the Store
    struct RGBState {
        bool red{false};
        bool green{false};
        bool blue{false};
        int pageIndex{0}; // index into QStackedWidget
        QString pageName{"home"};
    };


} // namespace flux

#endif // COLOR_ACTIONS_H


