/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alexander Grebien
 *
 * Created on 2. Dezember 2021, 10:07
 */

#include <cstdlib>
#include <cstdio>

#include <iostream>
#include "F1_UDP_Parser.h"

using namespace std;
unsigned char data[] = {
#include"data.h"
};

/*
 * 
 */
int main(int argc, char** argv)
{
    F1_UDP_Parser* parser = new F1_UDP_Parser();
    parser->push((char*)data);
    printf("Gang: %d", parser->packetCarTelemetryData()->m_carTelemetryData(0).m_gear);

    /*
    PacketCarTelemetryData* abst = new PacketCarTelemetryData((char*) data);
    printf("Klassenpointer: %p\n", abst);//->m_packetFormat());
    printf("Pointer auf erstes Element: %p\n\n", abst->pointerToFirstElement());//->m_packetFormat());
    printf("%d", abst->m_carTelemetryData(0).m_gear);
*/
    return 0;
}

