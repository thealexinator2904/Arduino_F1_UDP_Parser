/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AbstraktPaketClass.cpp
 * Author: Alexander Grebien
 * 
 * Created on 3. Dezember 2021, 17:24
 */
#include <string.h>

#include "AbstraktPaketClass.h"
#include <inttypes.h>
#include <cstdio>

using namespace std;

AbstraktPaketClass::AbstraktPaketClass()
{
    /*  printf("m_packetFormat_ %p\n", &m_header.m_packetFormat); //->m_packetFormat());
        printf("m_gameMajorVersion: %p\n", &m_header.m_gameMajorVersion); //->m_packetFormat());
        printf("m_gameMinorVersion: %p\n", &m_header.m_gameMinorVersion); //->m_packetFormat());
        printf("m_packetVersion: %p\n", &m_header.m_packetVersion); //->m_packetFormat());
        printf("m_packetId: %p\n", &m_header.m_packetId); //->m_packetFormat());
        printf("m_sessionUID: %p\n", &m_header.m_sessionUID); //->m_packetFormat());
        printf("m_secondaryPlayerCarIndex: %p\n", &m_header.m_secondaryPlayerCarIndex); //->m_packetFormat());*/
}

AbstraktPaketClass::~AbstraktPaketClass()
{
}

void AbstraktPaketClass::push(char *receiveBuffer)
{
    memmove(&m_header, receiveBuffer, 24);

}

uint16_t AbstraktPaketClass::m_packetFormat(void)
{
    return m_header.m_packetFormat;
}

uint8_t AbstraktPaketClass::m_gameMajorVersion(void)
{
    return m_header.m_gameMajorVersion;
}

uint8_t AbstraktPaketClass::m_gameMinorVersion(void)
{
    return m_header.m_gameMinorVersion;
}

uint8_t AbstraktPaketClass::m_packetVersion(void)
{
    return m_header.m_packetVersion;
}

uint8_t AbstraktPaketClass::m_packetId(void)
{
    return m_header.m_packetId;
}

uint64_t AbstraktPaketClass::m_sessionUID(void)
{
    return m_header.m_sessionUID;
}

float AbstraktPaketClass::m_sessionTime(void)
{
    return m_header.m_sessionTime;
}

uint32_t AbstraktPaketClass::m_frameIdentifier(void)
{
    return m_header.m_frameIdentifier;
}

uint8_t AbstraktPaketClass::m_playerCarIndex(void)
{
    return m_header.m_playerCarIndex;
}

uint8_t AbstraktPaketClass::m_secondaryPlayerCarIndex(void)
{
    return m_header.m_secondaryPlayerCarIndex;
}

uint16_t* AbstraktPaketClass::pointerToFirstElement(void)
{
    return &m_header.m_packetFormat;
}
