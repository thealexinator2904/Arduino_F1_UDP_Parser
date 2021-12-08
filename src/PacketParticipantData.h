/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketParticipantData.h
 * Author: Alexander Grebien
 *
 * Created on 4. Dezember 2021, 18:23
 */

#ifndef PACKETPARTICIPANTDATA_H
#define PACKETPARTICIPANTDATA_H

#include<inttypes.h>
#include "AbstraktPaketClass.h"

#pragma pack(push, 1)

struct ParticipantData
{
    uint8_t      m_aiControlled;           // Whether the vehicle is AI (1) or Human (0) controlled
    uint8_t      m_driverId;		// Driver id - see appendix, 255 if network human
    uint8_t      m_networkId;		// Network id – unique identifier for network players
    uint8_t      m_teamId;                 // Team id - see appendix
    uint8_t      m_myTeam;                 // My team flag – 1 = My Team, 0 = otherwise
    uint8_t      m_raceNumber;             // Race number of the car
    uint8_t      m_nationality;            // Nationality of the driver
    char       m_name[48];               // Name of participant in UTF-8 format – null terminated
					// Will be truncated with … (U+2026) if too long
    uint8_t      m_yourTelemetry;          // The player's UDP setting, 0 = restricted, 1 = public
};


class PacketParticipantData : public AbstraktPaketClass
{
public:
    PacketParticipantData(char * recieveBuffer);
    virtual ~PacketParticipantData();
        uint8_t           m_numActiveCars(void);	// Number of active cars in the data – should match number of
                                         // cars on HUD
    ParticipantData m_participants(int index);
private:
    uint8_t           m_numActiveCars_;	// Number of active cars in the data – should match number of
                                         // cars on HUD
    ParticipantData m_participants_[22];

};
#pragma pack(pop)

#endif /* PACKETPARTICIPANTDATA_H */

