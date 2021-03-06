/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PacketSessionData.h
 * Author: Alexander Grebien
 *
 * Created on 4. Dezember 2021, 17:28
 */

#ifndef PACKETSESSIONDATA_H
#define PACKETSESSIONDATA_H

#include<inttypes.h>
#include "AbstraktPaketClass.h"

#pragma pack(push, 1)

struct MarshalZone
{
    float m_zoneStart; // Fraction (0..1) of way through the lap the marshal zone starts
    int8_t m_zoneFlag; // -1 = invalid/unknown, 0 = none, 1 = green, 2 = blue, 3 = yellow, 4 = red
};

struct WeatherForecastSample
{
    uint8_t m_sessionType; // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P, 5 = Q1
    // 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ, 10 = R, 11 = R2
    // 12 = Time Trial
    uint8_t m_timeOffset; // Time in minutes the forecast is for
    uint8_t m_weather; // Weather - 0 = clear, 1 = light cloud, 2 = overcast
    // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t m_trackTemperature; // Track temp. in degrees Celsius
    int8_t m_trackTemperatureChange; // Track temp. change – 0 = up, 1 = down, 2 = no change
    int8_t m_airTemperature; // Air temp. in degrees celsius
    int8_t m_airTemperatureChange; // Air temp. change – 0 = up, 1 = down, 2 = no change
    uint8_t m_rainPercentage; // Rain percentage (0-100)
};

class PacketSessionData : public AbstraktPaketClass
{
public:
    PacketSessionData();
    virtual ~PacketSessionData();
    uint8_t m_weather(void); // Weather - 0 = clear, 1 = light cloud, 2 = overcast
    // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t m_trackTemperature(void); // Track temp. in degrees celsius
    int8_t m_airTemperature(void); // Air temp. in degrees celsius
    uint8_t m_totalLaps(void); // Total number of laps in this race
    uint16_t m_trackLength(void); // Track length in metres
    uint8_t m_sessionType(void); // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
    // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
    // 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
    int8_t m_trackId(void); // -1 for unknown, 0-21 for tracks, see appendix
    uint8_t m_formula(void); // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
    // 3 = F1 Generic
    uint16_t m_sessionTimeLeft(void); // Time left in session in seconds
    uint16_t m_sessionDuration(void); // Session duration in seconds
    uint8_t m_pitSpeedLimit(void); // Pit speed limit in kilometres per hour
    uint8_t m_gamePaused(void); // Whether the game is paused
    uint8_t m_isSpectating(void); // Whether the player is spectating
    uint8_t m_spectatorCarIndex(void); // Index of the car being spectated
    uint8_t m_sliProNativeSupport(void); // SLI Pro support, 0 = inactive, 1 = active
    uint8_t m_numMarshalZones(void); // Number of marshal zones to follow
    MarshalZone m_marshalZones(int index); // List of marshal zones – max 21
    uint8_t m_safetyCarStatus(void); // 0 = no safety car, 1 = full
    // 2 = virtual, 3 = formation lap
    uint8_t m_networkGame(void); // 0 = offline, 1 = online
    uint8_t m_numWeatherForecastSamples(void); // Number of weather samples to follow
    WeatherForecastSample m_weatherForecastSamples(int index); // Array of weather forecast samples
    uint8_t m_forecastAccuracy(void); // 0 = Perfect, 1 = Approximate
    uint8_t m_aiDifficulty(void); // AI Difficulty rating – 0-110
    uint32_t m_seasonLinkIdentifier(void); // Identifier for season - persists across saves
    uint32_t m_weekendLinkIdentifier(void); // Identifier for weekend - persists across saves
    uint32_t m_sessionLinkIdentifier(void); // Identifier for session - persists across saves
    uint8_t m_pitStopWindowIdealLap(void); // Ideal lap to pit on for current strategy (player)
    uint8_t m_pitStopWindowLatestLap(void); // Latest lap to pit on for current strategy (player)
    uint8_t m_pitStopRejoinPosition(void); // Predicted position to rejoin at (player)
    uint8_t m_steeringAssist(void); // 0 = off, 1 = on
    uint8_t m_brakingAssist(void); // 0 = off, 1 = low, 2 = medium, 3 = high
    uint8_t m_gearboxAssist(void); // 1 = manual, 2 = manual & suggested gear, 3 = auto
    uint8_t m_pitAssist(void); // 0 = off, 1 = on
    uint8_t m_pitReleaseAssist(void); // 0 = off, 1 = on
    uint8_t m_ERSAssist(void); // 0 = off, 1 = on
    uint8_t m_DRSAssist(void); // 0 = off, 1 = on
    uint8_t m_dynamicRacingLine(void); // 0 = off, 1 = corners only, 2 = full
    uint8_t m_dynamicRacingLineType(void); // 0 = 2D, 1 = 3D
    void push(char *receiveBuffer);

private:
    uint8_t m_weather_; // Weather - 0 = clear, 1 = light cloud, 2 = overcast
    // 3 = light rain, 4 = heavy rain, 5 = storm
    int8_t m_trackTemperature_; // Track temp. in degrees celsius
    int8_t m_airTemperature_; // Air temp. in degrees celsius
    uint8_t m_totalLaps_; // Total number of laps in this race
    uint16_t m_trackLength_; // Track length in metres
    uint8_t m_sessionType_; // 0 = unknown, 1 = P1, 2 = P2, 3 = P3, 4 = Short P
    // 5 = Q1, 6 = Q2, 7 = Q3, 8 = Short Q, 9 = OSQ
    // 10 = R, 11 = R2, 12 = R3, 13 = Time Trial
    int8_t m_trackId_; // -1 for unknown, 0-21 for tracks, see appendix
    uint8_t m_formula_; // Formula, 0 = F1 Modern, 1 = F1 Classic, 2 = F2,
    // 3 = F1 Generic
    uint16_t m_sessionTimeLeft_; // Time left in session in seconds
    uint16_t m_sessionDuration_; // Session duration in seconds
    uint8_t m_pitSpeedLimit_; // Pit speed limit in kilometres per hour
    uint8_t m_gamePaused_; // Whether the game is paused
    uint8_t m_isSpectating_; // Whether the player is spectating
    uint8_t m_spectatorCarIndex_; // Index of the car being spectated
    uint8_t m_sliProNativeSupport_; // SLI Pro support, 0 = inactive, 1 = active
    uint8_t m_numMarshalZones_; // Number of marshal zones to follow
    MarshalZone m_marshalZones_[21]; // List of marshal zones – max 21
    uint8_t m_safetyCarStatus_; // 0 = no safety car, 1 = full
    // 2 = virtual, 3 = formation lap
    uint8_t m_networkGame_; // 0 = offline, 1 = online
    uint8_t m_numWeatherForecastSamples_; // Number of weather samples to follow
    WeatherForecastSample m_weatherForecastSamples_[56]; // Array of weather forecast samples
    uint8_t m_forecastAccuracy_; // 0 = Perfect, 1 = Approximate
    uint8_t m_aiDifficulty_; // AI Difficulty rating – 0-110
    uint32_t m_seasonLinkIdentifier_; // Identifier for season - persists across saves
    uint32_t m_weekendLinkIdentifier_; // Identifier for weekend - persists across saves
    uint32_t m_sessionLinkIdentifier_; // Identifier for session - persists across saves
    uint8_t m_pitStopWindowIdealLap_; // Ideal lap to pit on for current strategy (player)
    uint8_t m_pitStopWindowLatestLap_; // Latest lap to pit on for current strategy (player)
    uint8_t m_pitStopRejoinPosition_; // Predicted position to rejoin at (player)
    uint8_t m_steeringAssist_; // 0 = off, 1 = on
    uint8_t m_brakingAssist_; // 0 = off, 1 = low, 2 = medium, 3 = high
    uint8_t m_gearboxAssist_; // 1 = manual, 2 = manual & suggested gear, 3 = auto
    uint8_t m_pitAssist_; // 0 = off, 1 = on
    uint8_t m_pitReleaseAssist_; // 0 = off, 1 = on
    uint8_t m_ERSAssist_; // 0 = off, 1 = on
    uint8_t m_DRSAssist_; // 0 = off, 1 = on
    uint8_t m_dynamicRacingLine_; // 0 = off, 1 = corners only, 2 = full
    uint8_t m_dynamicRacingLineType_; // 0 = 2D, 1 = 3D
};
#pragma pack(pop)

#endif /* PACKETSESSIONDATA_H */

