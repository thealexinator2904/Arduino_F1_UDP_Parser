/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketEventData.h
 * Author: Alexander Grebien
 *
 * Created on 4. Dezember 2021, 18:08
 */

#ifndef PACKETEVENTDATA_H
#define PACKETEVENTDATA_H

#include "AbstraktPaketClass.h"
#include<string>
// The event details packet is different for each type of event.
// Make sure only the correct type is interpreted.
#pragma pack(push, 1)

union EventDataDetails
{

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of car achieving fastest lap
        float lapTime; // Lap time is in seconds
    } FastestLap;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of car retiring
    } Retirement;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of team mate
    } TeamMateInPits;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the race winner
    } RaceWinner;

    struct
    {
        uint8_t penaltyType; // Penalty type – see Appendices
        uint8_t infringementType; // Infringement type – see Appendices
        uint8_t vehicleIdx; // Vehicle index of the car the penalty is applied to
        uint8_t otherVehicleIdx; // Vehicle index of the other car involved
        uint8_t time; // Time gained, or time spent doing action in seconds
        uint8_t lapNum; // Lap the penalty occurred on
        uint8_t placesGained; // Number of places gained by this
    } Penalty;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the vehicle triggering speed trap
        float speed; // Top speed achieved in kilometres per hour
        uint8_t overallFastestInSession; // Overall fastest speed in session = 1, otherwise 0
        uint8_t driverFastestInSession; // Fastest speed for driver in session = 1, otherwise 0
    } SpeedTrap;

    struct
    {
        uint8_t numLights; // Number of lights showing
    } StartLIghts;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the vehicle serving drive through
    } DriveThroughPenaltyServed;

    struct
    {
        uint8_t vehicleIdx; // Vehicle index of the vehicle serving stop go
    } StopGoPenaltyServed;

    struct
    {
        uint32_t flashbackFrameIdentifier; // Frame identifier flashed back to
        float flashbackSessionTime; // Session time flashed back to
    } Flashback;

    struct
    {
        uint32_t m_buttonStatus; // Bit flags specifying which buttons are being pressed
        // currently - see appendices
    } Buttons;
};

class PacketEventData : public AbstraktPaketClass
{
public:
    PacketEventData();
    virtual ~PacketEventData();
    uint8_t* m_eventStringCode(void);
    EventDataDetails m_eventDetails(void);
    void push(char *receiveBuffer);

private:
    uint8_t m_eventStringCode_[4]; // Event string code, see below
    EventDataDetails m_eventDetails_; // Event details - should be interpreted differently for each type
};
#pragma pack(pop)

#endif /* PACKETEVENTDATA_H */

