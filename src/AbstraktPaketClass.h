/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstraktPaketClass.h
 * Author: Alexander Grebien
 *
 * Created on 3. Dezember 2021, 17:24
 */

#ifndef ABSTRAKTPAKETCLASS_H
#define ABSTRAKTPAKETCLASS_H

#include<inttypes.h>

#pragma pack(push, 1)

struct PacketHeader
{
    uint16_t m_packetFormat; // 2021
    uint8_t m_gameMajorVersion; // Game major version - "X.00"
    uint8_t m_gameMinorVersion; // Game minor version - "1.XX"
    uint8_t m_packetVersion; // Version of this packet type, all start from 1
    uint8_t m_packetId; // Identifier for the packet type, see below
    uint64_t m_sessionUID; // Unique identifier for the session
    float m_sessionTime; // Session timestamp
    uint32_t m_frameIdentifier; // Identifier for the frame the data was retrieved on
    uint8_t m_playerCarIndex; // Index of player's car in the array
    uint8_t m_secondaryPlayerCarIndex; // Index of secondary player's car in the array (splitscreen)
    // 255 if no second player
};

using namespace std;

class AbstraktPaketClass
{
public:
    AbstraktPaketClass();
    virtual ~AbstraktPaketClass();
    uint16_t m_packetFormat(void); // 2021
    uint8_t m_gameMajorVersion(void); // Game major version - "X.00"
    uint8_t m_gameMinorVersion(void); // Game minor version - "1.XX"
    uint8_t m_packetVersion(void); // Version of this packet type, all start from 1
    uint8_t m_packetId(void); // Identifier for the packet type, see below
    uint64_t m_sessionUID(void); // Unique identifier for the session
    float m_sessionTime(void); // Session timestamp
    uint32_t m_frameIdentifier(void); // Identifier for the frame the data was retrieved on
    uint8_t m_playerCarIndex(void); // Index of player's car in the array
    uint8_t m_secondaryPlayerCarIndex(void);
    void push(char *receiveBuffer);

protected:
    PacketHeader m_header;
    uint16_t* pointerToFirstElement();
};

#pragma pack(pop)

#endif /* ABSTRAKTPAKETCLASS_H */

