#include "ATM_FSM.h"
#include <iostream>

using namespace fsmlite;


void ATM_recycle::Checkdevice_failed_Act()
{
    std::cout << "DeviceFailedEvt/n" << std::endl;
}

void ATM_recycle::Checkgarbagelv_failed_Act()
{
    std::cout << "GarbageLvMaxEvt/n" << std::endl;
}
void ATM_recycle::Check_complete_Act()
{
    std::cout << "CheckingCompEvt/n" << std::endl;
}
void ATM_recycle::Check_ID_Act()
{
    std::cout << "Check_ID_Act/n" << std::endl;
}
void ATM_recycle::Check_ID_comp_Act()
{
    std::cout << "Check_ID_comp_Act/n" << std::endl;
}
void ATM_recycle::Check_ID_failed_Act()
{
    std::cout << "Check_ID_failed_Act/n" << std::endl;
}
void ATM_recycle::identification_failed_Act()
{
    std::cout << "identification_failed_Act/n" << std::endl;
}
void ATM_recycle::identification_comp_Act()
{
    std::cout << "identification_comp_Act/n" << std::endl;
}
void ATM_recycle::Get_newgar_Act()
{
    std::cout << "Get_newgar_Act/n" << std::endl;
}
void ATM_recycle::Close_work_Act()
{
    std::cout << "Close_work_Act/n" << std::endl;
}
void ATM_recycle::Require_ident_Act()
{
    std::cout << "Require_ident_Act/n" << std::endl;
}
void ATM_recycle::Require_login_Act()
{
    std::cout << "Require_login_Act/n" << std::endl;
}
