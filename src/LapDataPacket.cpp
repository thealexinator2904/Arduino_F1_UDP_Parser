/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LapDataPacket.cpp
 * Author: Alexander Grebien
 * 
 * Created on 4. Dezember 2021, 18:00
 */

#include "LapDataPacket.h"
#include<string.h>

LapDataPacket::LapDataPacket()
: AbstraktPaketClass()
{
}

LapDataPacket::~LapDataPacket()
{
}

void LapDataPacket::push(char *receiveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), receiveBuffer, 970);
}

LapData LapDataPacket::m_lapData(char index)
{
    if (index >= 0 && index < 22)
        return m_lapData_[index];
    else return {0};
}
