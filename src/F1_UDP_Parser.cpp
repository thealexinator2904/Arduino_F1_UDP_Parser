/* 
 * File:   F1_UDP_Parser.cpp
 * Author: Alexander Grebien
 * 
 * Created on 2. Dezember 2021, 11:01
 */

#include <stdio.h>

#include "F1_UDP_Parser.h"
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

F1_UDP_Parser::F1_UDP_Parser()
{
    packetMotionData_ = new PacketMotionData();
    packetSessionData_ = new PacketSessionData();
    lapDataPacket_ = new LapDataPacket();
    packetEventData_ = new PacketEventData();
    packetParticipantData_ = new PacketParticipantData();
    packetCarSetupData_ = new PacketCarSetupData();
    packetCarTelemetryData_ = new PacketCarTelemetryData();
    packetCarStatusData_ = new PacketCarStatusData();
    packetFinalClassificationData_ = new PacketFinalClassificationData();
    packetLobbyInfoData_ = new PacketLobbyInfoData();
    packetCarDamageData_ = new PacketCarDamageData();
    packetSessionData_ = new PacketSessionData();
}

F1_UDP_Parser::~F1_UDP_Parser()
{
    delete packetMotionData_;
    delete packetSessionData_;
    delete lapDataPacket_;
    delete packetEventData_;
    delete packetParticipantData_;
    delete packetCarSetupData_;
    delete packetCarTelemetryData_;
    delete packetCarStatusData_;
    delete packetFinalClassificationData_;
    delete packetLobbyInfoData_;
    delete packetCarDamageData_;
    delete packetSessionData_;
    delete packetSessionHistoryData_;
}

void F1_UDP_Parser::push(char * recieveBuffer)
{
    AbstraktPaketClass* abs = new AbstraktPaketClass();
    abs->push(recieveBuffer);
    switch (abs->m_packetId())
    {
        case 0: packetMotionData_->push(recieveBuffer);
            break;
        case 1: packetSessionData_->push(recieveBuffer);
            break;
        case 2: lapDataPacket_->push(recieveBuffer);
            break;
        case 3: packetEventData_->push(recieveBuffer);
            break;
        case 4: packetParticipantData_->push(recieveBuffer);
            break;
        case 5: packetCarSetupData_->push(recieveBuffer);
            break;
        case 6: packetCarTelemetryData_->push(recieveBuffer);
            break;
        case 7: packetCarStatusData_->push(recieveBuffer);
            break;
        case 8: packetFinalClassificationData_->push(recieveBuffer);
            break;
        case 9: packetLobbyInfoData_->push(recieveBuffer);
            break;
        case 10: packetCarDamageData_->push(recieveBuffer);
            break;
        case 11: packetSessionHistoryData_->push(recieveBuffer);
            break;
        default:;
    }
    delete abs;
}

PacketMotionData* F1_UDP_Parser::packetMotionData(void)
{
    return packetMotionData_;
}

PacketSessionData* F1_UDP_Parser::packetSessionData(void)
{
    return packetSessionData_;
}

LapDataPacket* F1_UDP_Parser::lapDataPacket(void)
{
    return lapDataPacket_;
}

PacketEventData* F1_UDP_Parser::packetEventData(void)
{
    return packetEventData_;
}

PacketParticipantData* F1_UDP_Parser::packetParticipantData(void)
{
    return packetParticipantData_;
}

PacketCarSetupData* F1_UDP_Parser::packetCarSetupData(void)
{
    return packetCarSetupData_;
}

PacketCarTelemetryData* F1_UDP_Parser::packetCarTelemetryData(void)
{
    return packetCarTelemetryData_;
}

PacketCarStatusData* F1_UDP_Parser::packetCarStatusData(void)
{
    return packetCarStatusData_;
}

PacketFinalClassificationData* F1_UDP_Parser::packetFinalClassificationData(void)
{
    return packetFinalClassificationData_;
}

PacketLobbyInfoData* F1_UDP_Parser::packetLobbyInfoData(void)
{
    return packetLobbyInfoData_;
}

PacketCarDamageData* F1_UDP_Parser::packetCarDamageData(void)
{
    return packetCarDamageData_;
}

PacketSessionHistoryData* F1_UDP_Parser::packetSessionHistoryData(void)
{
    return packetSessionHistoryData_;
}
