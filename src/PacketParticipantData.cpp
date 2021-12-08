/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketParticipantData.cpp
 * Author: Alexander Grebien
 * 
 * Created on 4. Dezember 2021, 18:23
 */

#include "PacketParticipantData.h"
#include<inttypes.h>
#include<string.h>

PacketParticipantData::PacketParticipantData(char * recieveBuffer)
: AbstraktPaketClass(recieveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), recieveBuffer, 1257);
}

PacketParticipantData::~PacketParticipantData()
{
}

uint8_t PacketParticipantData::m_numActiveCars(void)
{
    return m_numActiveCars_;
}

ParticipantData PacketParticipantData::m_participants(int index)
{
    if (index >= 0 && index < 22)
        return m_participants_[index];
    else return{0};
}