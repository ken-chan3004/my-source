#include "FSMHelper.h"
#include <iostream>

const char* FsmHelper::toStateName(int state)
{
    //todo: [TaiTN] clean up duplication
    enum states {
        INIT,              //!< State of beginning project
        RUNNING,           //!< State of processing
        ERROR_DEVICE,      //!< State of processing when another device disconnected
        ERROR_GARBAGE_FULL, //!< State when the level of garbage is max

        // for RUNNING substate
        IDLE,           //!< State of beginning Running substate
        LOGIN,          //!< State of Login
        PROCESSING,     //!< State of indentification
        REJECT,         //!< State of rechecking garbage
        POST_PROCESSING //!< State of stored point
    };
    switch (static_cast<states>(state))
    {
    case states::INIT:
        return "INIT";
    case states::RUNNING:
        return "RUNNING";
    case states::ERROR_DEVICE:
        return "ERROR_DEVICE";
    case states::ERROR_GARBAGE_FULL:
        return "ERROR_GARBAGE_FULL";

        //case for RUNNING substate
    case states::IDLE:
        return "IDLE";
    case states::LOGIN:
        return "LOGIN";
    case states::PROCESSING:
        return "PROCESSING";
    case states::REJECT:
        return "REJECT";
    case states::POST_PROCESSING:
        return "POST_PROCESSING";

    default:
        std::cout << "ERROR UNKNOWN STATE !" << std::endl;
        return "UNKNOWN";
    }
}