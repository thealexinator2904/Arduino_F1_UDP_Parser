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

#include "PacketLobbyInfoData.h"

PacketLobbyInfoData::PacketLobbyInfoData()
: AbstraktPaketClass()
{
}

PacketLobbyInfoData::~PacketLobbyInfoData()
{
}

void PacketLobbyInfoData::push(char *receiveBuffer)
{
    AbstraktPaketClass::push(receiveBuffer);
    //memmove(AbstraktPaketClass::pointerToFirstElement(), receiveBuffer, 1);
}