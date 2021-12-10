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

#include "PacketFinalClassificationData.h"
#include<inttypes.h>
#include<string.h>

PacketFinalClassificationData::PacketFinalClassificationData()
: AbstraktPaketClass()
{
    //memmove(AbstraktPaketClass::pointerToFirstElement(), recieveBuffer, 839);
}

PacketFinalClassificationData::~PacketFinalClassificationData()
{
}

void PacketFinalClassificationData::push(char *receiveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), receiveBuffer, 839);
}

uint8_t m_numCars(void)
{
    return m_numCars();
}

FinalClassificationData PacketFinalClassificationData::m_classificationData(int index)
{
    if (index >= 0 && index < 22)
        return m_classificationData_[index];
    else return {0};
}