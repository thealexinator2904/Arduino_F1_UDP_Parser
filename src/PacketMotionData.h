/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketMotionData.h
 * Author: Alexander Grebien
 *
 * Created on 3. Dezember 2021, 20:13
 */

#ifndef PACKETMOTIONDATA_H
#define PACKETMOTIONDATA_H

#include "AbstraktPaketClass.h"

#pragma pack(push, 1)

struct CarMotionData
{
    float m_worldPositionX; // World space X position
    float m_worldPositionY; // World space Y position
    float m_worldPositionZ; // World space Z position
    float m_worldVelocityX; // Velocity in world space X
    float m_worldVelocityY; // Velocity in world space Y
    float m_worldVelocityZ; // Velocity in world space Z
    int16_t m_worldForwardDirX; // World space forward X direction (normalised)
    int16_t m_worldForwardDirY; // World space forward Y direction (normalised)
    int16_t m_worldForwardDirZ; // World space forward Z direction (normalised)
    int16_t m_worldRightDirX; // World space right X direction (normalised)
    int16_t m_worldRightDirY; // World space right Y direction (normalised)
    int16_t m_worldRightDirZ; // World space right Z direction (normalised)
    float m_gForceLateral; // Lateral G-Force component
    float m_gForceLongitudinal; // Longitudinal G-Force component
    float m_gForceVertical; // Vertical G-Force component
    float m_yaw; // Yaw angle in radians
    float m_pitch; // Pitch angle in radians
    float m_roll; // Roll angle in radians
};

class PacketMotionData : public AbstraktPaketClass
{
public:
    PacketMotionData();
    virtual ~PacketMotionData();
    // Extra player car ONLY data
    CarMotionData m_carMotionData(int index);
    float m_suspensionPosition(char index); // Note: All wheel arrays have the following order:
    float m_suspensionVelocity(char index); // RL, RR, FL, FR
    float m_suspensionAcceleration(char index); // RL, RR, FL, FR
    float m_wheelSpeed(char index); // Speed of each wheel
    float m_wheelSlip(char index); // Slip ratio for each wheel
    float m_localVelocityX(void); // Velocity in local space
    float m_localVelocityY(void); // Velocity in local space
    float m_localVelocityZ(void); // Velocity in local space
    float m_angularVelocityX(void); // Angular velocity x-component
    float m_angularVelocityY(void); // Angular velocity y-component
    float m_angularVelocityZ(void); // Angular velocity z-component
    float m_angularAccelerationX(void); // Angular velocity x-component
    float m_angularAccelerationY(void); // Angular velocity y-component
    float m_angularAccelerationZ(void); // Angular velocity z-component
    float m_frontWheelsAngle(void);
    void push(char *receiveBuffer);

private:
    CarMotionData m_carMotionData_[22]; //22 elements
    // Extra player car ONLY data
    float m_suspensionPosition_[4]; // Note: All wheel arrays have the following order:
    float m_suspensionVelocity_[4]; // RL, RR, FL, FR
    float m_suspensionAcceleration_[4]; // RL, RR, FL, FR
    float m_wheelSpeed_[4]; // Speed of each wheel
    float m_wheelSlip_[4]; // Slip ratio for each wheel
    float m_localVelocityX_; // Velocity in local space
    float m_localVelocityY_; // Velocity in local space
    float m_localVelocityZ_; // Velocity in local space
    float m_angularVelocityX_; // Angular velocity x-component
    float m_angularVelocityY_; // Angular velocity y-component
    float m_angularVelocityZ_; // Angular velocity z-component
    float m_angularAccelerationX_; // Angular velocity x-component
    float m_angularAccelerationY_; // Angular velocity y-component
    float m_angularAccelerationZ_; // Angular velocity z-component
    float m_frontWheelsAngle_; // Current front wheels angle in radians
};
#pragma pack(pop)

#endif /* PACKETMOTIONDATA_H */

