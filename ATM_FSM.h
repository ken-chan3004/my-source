#include "FSM.h"

#include <string>

class ATM_recycle: public fsmlite::fsm<ATM_recycle> {
    // grant base class access to private transition_table
    friend class fsmlite::fsm<ATM_recycle>;

public:
      enum states {
        INIT,               //!< State of beginning project
        RUNNING,            //!< State of processing
        ERROR_DEVICE,       //!< State of processing when another device disconnected
        ERROR_GARBAGE_FULL, //!< State when the level of garbage is max
        IDLE,               //!< State of beginning Running substate
        LOGIN,              //!< State of Login
        PROCESSING,         //!< State of indentification
        REJECT,             //!< State of rechecking garbage
        POST_PROCESSING     //!< State of stored point
      };

    ATM_recycle(state_type init_state = INIT) : fsm(init_state) {}

    /*!
     * @brief Simple event declare as below
     *         This contains only simple struct as an event of main Finite State Machine
     */
    //! @brief Event checking failed device, notification error of devices
    struct DeviceFailedEvt {};
    //! @brief Event checking failed garbage level max, notification error of garbage level is max
    struct GarbageLvMaxEvt {};
    //! @brief Event complete checking device and gargabe level, devices run and garbage level is free
    struct CheckingCompEvt {};

    /*!
     * @brief Simple event declare as below
     *         This contains only simple struct as an event of SubStateMachine
     */
    //! @brief Event checking ID, it will check the ID card or ID account from keyboard
    struct CheckingIDSubAtmEvt {};
    //! @brief Event checking ID completes, it will move to PROCESSING state
    struct CheckingIDCompEvt {};
    //! @brief Event checking ID is failed, it will check ID again
    struct CheckingIDFailedEvt {};
    //! @brief Event indentification is failed, it will move to REJECT state
    struct UnIdentEvt {};
    //! @brief Even indetification complete, it will move to POST_PROCESSING state
    struct IdentEvt {};
    //! @brief Event getting newgarbage when the garbage cannot indentify
    struct GetnewGarEvt {};
    //! @brief Event closing the work, and waiting a new login if the garbage cannot identify
    struct ClosingEvt {};
    //! @brief Event requiring indentification if the garbage cannot identify
    struct RepeatIdentEvt {};
    //! @brief Event requiring login when complete post point and information
    struct RepeatLoginEvt {};

public:
     // actions for main FSM
    
    void Checkdevice_failed_Act();
    
    void Checkgarbagelv_failed_Act();
    
    void Check_complete_Act();

    // action for RUNNING substate
    
    void Check_ID_Act();
    
    void Check_ID_comp_Act();
    
    void Check_ID_failed_Act();
    
    void identification_failed_Act();
    
    void identification_comp_Act();
   
    void Get_newgar_Act();
    
    void Close_work_Act();
    
    void Require_ident_Act();
    
    void Require_login_Act();

private:
    using m = ATM_recycle;  // for brevity
    
    using transition_table = table<
        //                 Start                Event                 Target                        Action                  Guard
        //---------+-------------------+------------------------+-------------------------+-------------------------------+-----------+
        row<            INIT,            DeviceFailedEvt,       ERROR_DEVICE,           &m::Checkdevice_failed_Act      /*none*/ >,
        row<            INIT,            GarbageLvMaxEvt,       ERROR_GARBAGE_FULL,     &m::Checkgarbagelv_failed_Act   /*none*/ >,
        row<            INIT,            CheckingCompEvt,       RUNNING,                &m::Check_complete_Act          /*none*/ >,
        row<            LOGIN,           CheckingIDFailedEvt,   LOGIN,                  &m::Check_ID_failed_Act         /*none*/ >,
        row<            LOGIN,           CheckingIDCompEvt,     PROCESSING,             &m::Check_ID_comp_Act           /*none*/ >,
        row<            PROCESSING,      UnIdentEvt,            REJECT,                 &m::identification_failed_Act   /*none*/ >,
        row<            PROCESSING,      IdentEvt,              POST_PROCESSING,        &m::identification_comp_Act     /*none*/ >,
        row<            POST_PROCESSING, GetnewGarEvt,          PROCESSING,             &m::Get_newgar_Act              /*none*/ >,
        row<            REJECT,          ClosingEvt,            LOGIN,                  &m::Close_work_Act              /*none*/ >,
        row<            REJECT,          RepeatIdentEvt,        PROCESSING,             &m::Require_ident_Act           /*none*/ >,
        row<            POST_PROCESSING, RepeatLoginEvt,        LOGIN,                  &m::Require_login_Act           /*none*/ >>;
};