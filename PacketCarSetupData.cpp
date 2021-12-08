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

#include "PacketCarSetupData.h"
#include<string.h>

PacketCarSetupData::PacketCarSetupData(char * recieveBuffer)
: AbstraktPaketClass(recieveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), recieveBuffer, 1102);
}

PacketCarSetupData::~PacketCarSetupData()
{
}

CarSetupData PacketCarSetupData::m_carSetups(int index)
{
    if (index >= 0 && index < 22)
        return m_carSetups_[index];
    else return {0};
}
