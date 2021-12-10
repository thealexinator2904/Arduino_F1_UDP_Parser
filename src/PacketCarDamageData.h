/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketCarSetupData.h
 * Author: Alexander Grebien
 *
 * Created on 4. Dezember 2021, 18:30
 */

#ifndef PACKETCARDAMAGEDATA_H
#define PACKETCARDAMAGEDATA_H

#include<inttypes.h>
#include "AbstraktPaketClass.h"

#pragma pack(push, 1)

struct CarDamageData
{
    float m_tyresWear[4]; // Tyre wear (percentage)
    uint8_t m_tyresDamage[4]; // Tyre damage (percentage)
    uint8_t m_brakesDamage[4]; // Brakes damage (percentage)
    uint8_t m_frontLeftWingDamage; // Front left wing damage (percentage)
    uint8_t m_frontRightWingDamage; // Front right wing damage (percentage)
    uint8_t m_rearWingDamage; // Rear wing damage (percentage)
    uint8_t m_floorDamage; // Floor damage (percentage)
    uint8_t m_diffuserDamage; // Diffuser damage (percentage)
    uint8_t m_sidepodDamage; // Sidepod damage (percentage)
    uint8_t m_drsFault; // Indicator for DRS fault, 0 = OK, 1 = fault
    uint8_t m_gearBoxDamage; // Gear box damage (percentage)
    uint8_t m_engineDamage; // Engine damage (percentage)
    uint8_t m_engineMGUHWear; // Engine wear MGU-H (percentage)
    uint8_t m_engineESWear; // Engine wear ES (percentage)
    uint8_t m_engineCEWear; // Engine wear CE (percentage)
    uint8_t m_engineICEWear; // Engine wear ICE (percentage)
    uint8_t m_engineMGUKWear; // Engine wear MGU-K (percentage)
    uint8_t m_engineTCWear; // Engine wear TC (percentage)
};

class PacketCarDamageData : public AbstraktPaketClass
{
public:
    PacketCarDamageData();
    virtual ~PacketCarDamageData();
    void push(char *receiveBuffer);

private:
    CarDamageData m_carDamageData[22];
};
#pragma pack(pop)

#endif /* PACKETCARDAMAGEDATA_H */

