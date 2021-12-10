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

PacketCarSetupData::PacketCarSetupData()
: AbstraktPaketClass()
{
}

PacketCarSetupData::~PacketCarSetupData()
{
}

void PacketCarSetupData::push(char *receiveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), receiveBuffer, 1102);
}

CarSetupData PacketCarSetupData::m_carSetups(int index)
{
    if (index >= 0 && index < 22)
        return m_carSetups_[index];
    else return {0};
}
