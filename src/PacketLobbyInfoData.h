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

#ifndef PACKETLOBBYINFODATA_H
#define PACKETLOBBYINFODATA_H

#include<inttypes.h>
#include "AbstraktPaketClass.h"

#pragma pack(push, 1)

struct LobbyInfoData
{
    uint8_t m_aiControlled; // Whether the vehicle is AI (1) or Human (0) controlled
    uint8_t m_teamId; // Team id - see appendix (255 if no team currently selected)
    uint8_t m_nationality; // Nationality of the driver
    char m_name[48]; // Name of participant in UTF-8 format – null terminated
    // Will be truncated with ... (U+2026) if too long
    uint8_t m_carNumber; // Car number of the player
    uint8_t m_readyStatus; // 0 = not ready, 1 = ready, 2 = spectating
};

class PacketLobbyInfoData : public AbstraktPaketClass
{
public:
    PacketLobbyInfoData();
    virtual ~PacketLobbyInfoData();
    // Packet specific data
    uint8_t m_numPlayers(void); // Number of players in the lobby data
    LobbyInfoData m_lobbyPlayers(int index);
    void push(char *receiveBuffer);

private:
    // Packet specific data
    uint8_t m_numPlayers_; // Number of players in the lobby data
    LobbyInfoData m_lobbyPlayers_[22];
};
#pragma pack(pop)

#endif /* PACKETLOBBYINFODATA_H */

