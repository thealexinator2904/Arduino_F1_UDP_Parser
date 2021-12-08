/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketEventData.cpp
 * Author: Alexander Grebien
 * 
 * Created on 4. Dezember 2021, 18:08
 */

#include "PacketEventData.h"
#include<string.h>

PacketEventData::PacketEventData(char * recieveBuffer)
: AbstraktPaketClass(recieveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), recieveBuffer, 36);
}

PacketEventData::~PacketEventData()
{
}

uint8_t* PacketEventData::m_eventStringCode(void)
{

    return m_eventStringCode_;
}

EventDataDetails PacketEventData::m_eventDetails(void)
{
    return m_eventDetails_;
}