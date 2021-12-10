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

#include "PacketCarTelemetryData.h"
#include<string.h>

PacketCarTelemetryData::PacketCarTelemetryData()
: AbstraktPaketClass()
{

}

PacketCarTelemetryData::~PacketCarTelemetryData()
{
}

void PacketCarTelemetryData::push(char *receiveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), receiveBuffer, 1347);
}


CarTelemetryData PacketCarTelemetryData::m_carTelemetryData(int index)
{
    if (index >= 0 && index < 22)
        return m_carTelemetryData_[index];
    else return {0};
}

uint8_t PacketCarTelemetryData::m_mfdPanelIndex(void)
{
    return m_mfdPanelIndex_;
}

uint8_t PacketCarTelemetryData::m_mfdPanelIndexSecondaryPlayer(void)
{
    return m_mfdPanelIndexSecondaryPlayer_;
}

int8_t PacketCarTelemetryData::m_suggestedGear(void)
{
    return m_suggestedGear_;
}