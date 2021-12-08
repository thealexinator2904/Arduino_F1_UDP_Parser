/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   F1_UDP_Parser.h
 * Author: Alexander Grebien
 *
 * Created on 2. Dezember 2021, 11:01
 */

#ifndef F1_UDP_PARSER_H
#define F1_UDP_PARSER_H

#include "PacketSessionHistoryData.h"
#include "PacketMotionData.h"
#include "PacketSessionData.h"
#include "LapDataPacket.h"
#include "PacketEventData.h"
#include "PacketParticipantData.h"
#include "PacketCarSetupData.h"
#include "PacketCarTelemetryData.h"
#include "PacketCarStatusData.h"
#include "PacketFinalClassificationData.h"
#include "PacketLobbyInfoData.h"
#include "PacketCarDamageData.h"
#include "PacketSessionHistoryData.h"

class F1_UDP_Parser
{
public:
    F1_UDP_Parser();
    virtual ~F1_UDP_Parser();
    void push(char * recieveBuffer);
    PacketMotionData* packetMotionData(void);
    PacketSessionData* packetSessionData(void);
    LapDataPacket* lapDataPacket(void);
    PacketEventData* packetEventData(void);
    PacketParticipantData* packetParticipantData(void);
    PacketCarSetupData* packetCarSetupData(void);
    PacketCarTelemetryData* packetCarTelemetryData(void);
    PacketCarStatusData* packetCarStatusData(void);
    PacketFinalClassificationData* packetFinalClassificationData(void);
    PacketLobbyInfoData* packetLobbyInfoData(void);
    PacketCarDamageData* packetCarDamageData(void);
    PacketSessionHistoryData* packetSessionHistoryData(void);

private:
    PacketMotionData* packetMotionData_;
    PacketSessionData* packetSessionData_;
    LapDataPacket* lapDataPacket_;
    PacketEventData* packetEventData_;
    PacketParticipantData* packetParticipantData_;
    PacketCarSetupData* packetCarSetupData_;
    PacketCarTelemetryData* packetCarTelemetryData_;
    PacketCarStatusData* packetCarStatusData_;
    PacketFinalClassificationData* packetFinalClassificationData_;
    PacketLobbyInfoData* packetLobbyInfoData_;
    PacketCarDamageData* packetCarDamageData_;
    PacketSessionHistoryData* packetSessionHistoryData_;

};

#endif /* F1_UDP_PARSER_H */

