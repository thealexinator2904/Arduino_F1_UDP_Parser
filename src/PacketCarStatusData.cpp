/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketCarSetupData.cpp
 * Author: Alexander Grebien
 * 
 * Created on 4. Dezember 2021, 18:30
 */

#include "PacketCarStatusData.h"
#include<string.h>

PacketCarStatusData::PacketCarStatusData(char * recieveBuffer)
: AbstraktPaketClass(recieveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), recieveBuffer, 1058);

}

PacketCarStatusData::~PacketCarStatusData()
{
}

CarStatusData PacketCarStatusData::m_carStatusData(int index)
{
    if (index >= 0 && index < 22)
        return m_carStatusData_[index];
    else return {0};
}

