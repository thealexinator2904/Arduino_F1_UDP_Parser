/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketMotionData.cpp
 * Author: Alexander Grebien
 * 
 * Created on 3. Dezember 2021, 20:13
 */

#include "PacketMotionData.h"
#include<string.h>

PacketMotionData::PacketMotionData(char* recieveBuffer)
: AbstraktPaketClass(recieveBuffer)
{
    memmove(AbstraktPaketClass::pointerToFirstElement(), recieveBuffer, 1464);
}

PacketMotionData::~PacketMotionData()
{
}

CarMotionData PacketMotionData::m_carMotionData(int index)
{
    if (index < 22 && index >= 0)
        return m_carMotionData_[index];
    else return {-1};
}

float PacketMotionData::m_suspensionPosition(char index)
{
    if (index < 4 && index >= 0)
        return m_suspensionPosition_[index];
    else
        return 0;
}

float PacketMotionData::m_suspensionVelocity(char index)
{
    if (index < 4 && index >= 0)
        return m_suspensionPosition_[index];
    else
        return 0;
}

float PacketMotionData::m_suspensionAcceleration(char index)
{
    if (index < 4 && index >= 0)
        return m_suspensionAcceleration_[index];
    else
        return 0;
}

float PacketMotionData::m_wheelSpeed(char index)
{
    if (index < 4 && index >= 0)
        return m_wheelSpeed_[index];
    else
        return 0;
}

float PacketMotionData::m_wheelSlip(char index)
{
    if (index < 4 && index >= 0)
        return m_wheelSlip_[index];
    else
        return 0;
}

float PacketMotionData::m_localVelocityX(void)
{
    return m_localVelocityX_;
} // Velocity in local space

float PacketMotionData::m_localVelocityY(void)
{
    return m_localVelocityY_;
}

float PacketMotionData::m_localVelocityZ(void)
{
    return m_localVelocityZ_;
}

float PacketMotionData::m_angularVelocityX(void)
{
    return m_angularVelocityX_;
}

float PacketMotionData::m_angularVelocityY(void)
{
    return m_angularVelocityY_;
}

float PacketMotionData::m_angularVelocityZ(void)
{
    return m_angularVelocityZ_;
}

float PacketMotionData::m_angularAccelerationX(void)
{
    return m_angularAccelerationX_;
} // Angular velocity x-component

float PacketMotionData::m_angularAccelerationY(void)
{
    return m_angularAccelerationY_;
} // Angular velocity y-component

float PacketMotionData::m_angularAccelerationZ(void)
{
    return m_angularAccelerationZ_;
} // Angular velocity z-component

float PacketMotionData::m_frontWheelsAngle(void)
{
    return m_frontWheelsAngle_;
}