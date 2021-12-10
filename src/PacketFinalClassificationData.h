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

#ifndef PACKETFINALCLASSIFICATIONDATA_H
#define PACKETFINALCLASSIFICATIONDATA_H

#include<inttypes.h>
#include "AbstraktPaketClass.h"

#pragma pack(push, 1)

struct FinalClassificationData
{
    uint8_t m_position; // Finishing position
    uint8_t m_numLaps; // Number of laps completed
    uint8_t m_gridPosition; // Grid position of the car
    uint8_t m_points; // Number of points scored
    uint8_t m_numPitStops; // Number of pit stops made
    uint8_t m_resultStatus; // Result status - 0 = invalid, 1 = inactive, 2 = active
    // 3 = finished, 4 = didnotfinish, 5 = disqualified
    // 6 = not classified, 7 = retired
    uint32_t m_bestLapTimeInMS; // Best lap time of the session in milliseconds
    double m_totalRaceTime; // Total race time in seconds without penalties
    uint8_t m_penaltiesTime; // Total penalties accumulated in seconds
    uint8_t m_numPenalties; // Number of penalties applied to this driver
    uint8_t m_numTyreStints; // Number of tyres stints up to maximum
    uint8_t m_tyreStintsActual[8]; // Actual tyres used by this driver
    uint8_t m_tyreStintsVisual[8]; // Visual tyres used by this driver
};

class PacketFinalClassificationData : public AbstraktPaketClass
{
public:
    PacketFinalClassificationData();
    virtual ~PacketFinalClassificationData();
    uint8_t m_numCars(void); // Number of cars in the final classification
    FinalClassificationData m_classificationData(int index);
    void push(char *receiveBuffer);

private:
    uint8_t m_numCars_; // Number of cars in the final classification
    FinalClassificationData m_classificationData_[22];
};
#pragma pack(pop)

#endif /* PACKETFINALCLASSIFICATIONDATA_H */

