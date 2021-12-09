/* 
 * File:   F1_UDP_Parser.cpp
 * Author: Alexander Grebien
 * 
 * Created on 2. Dezember 2021, 11:01
 */


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

#include <stdio.h>
#include <stdlib.h>

F1_UDP_Parser::F1_UDP_Parser()
{
    char * exampleBuffer;
    exampleBuffer = (char *) malloc(1500);
    
    packetMotionData_ = new PacketMotionData(exampleBuffer);
    packetSessionData_ = new PacketSessionData(exampleBuffer);
    lapDataPacket_ = new LapDataPacket(exampleBuffer);
    packetEventData_ = new PacketEventData(exampleBuffer);
    packetParticipantData_ = new PacketParticipantData(exampleBuffer);
    packetCarSetupData_ = new PacketCarSetupData(exampleBuffer);
    packetCarTelemetryData_ = new PacketCarTelemetryData(exampleBuffer);
    packetCarStatusData_ = new PacketCarStatusData(exampleBuffer);
    packetFinalClassificationData_ = new PacketFinalClassificationData(exampleBuffer);
    packetLobbyInfoData_ = new PacketLobbyInfoData(exampleBuffer);
    packetCarDamageData_ = new PacketCarDamageData(exampleBuffer);
    packetSessionData_ = new PacketSessionData(exampleBuffer);
    free(exampleBuffer);
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
    AbstraktPaketClass* abs = new AbstraktPaketClass(recieveBuffer);
    switch (abs->m_packetId())
    {
        case 0: delete packetMotionData_;
            packetMotionData_ = new PacketMotionData(recieveBuffer);
            break;
        case 1: delete packetSessionData_;
            packetSessionData_ = new PacketSessionData(recieveBuffer);
            break;
        case 2: delete lapDataPacket_;
            lapDataPacket_ = new LapDataPacket(recieveBuffer);
            break;
        case 3: delete packetEventData_;
            packetEventData_ = new PacketEventData(recieveBuffer);
            break;
        case 4: delete packetParticipantData_;
            packetParticipantData_ = new PacketParticipantData(recieveBuffer);
            break;
        case 5: delete packetCarSetupData_;
            packetCarSetupData_ = new PacketCarSetupData(recieveBuffer);
            break;
        case 6: delete packetCarTelemetryData_;
            packetCarTelemetryData_ = new PacketCarTelemetryData(recieveBuffer);
            break;
        case 7: delete packetCarStatusData_;
            packetCarStatusData_ = new PacketCarStatusData(recieveBuffer);
            break;
        case 8: delete packetFinalClassificationData_;
            packetFinalClassificationData_ = new PacketFinalClassificationData(recieveBuffer);
            break;
        case 9: delete packetLobbyInfoData_;
            packetLobbyInfoData_ = new PacketLobbyInfoData(recieveBuffer);
            break;
        case 10: delete packetCarDamageData_;
            packetCarDamageData_ = new PacketCarDamageData(recieveBuffer);
            break;
        case 11: delete packetSessionHistoryData_;
            packetSessionHistoryData_ = new PacketSessionHistoryData(recieveBuffer);
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
