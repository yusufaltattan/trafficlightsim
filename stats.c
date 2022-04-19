#include <stdio.h>
#include "stats.h"

extern void printStatistics(AVERAGE_STATS *stats) {
    printf("\n");
    printf("\t Parameter Values: \n");
    printf("\t \t from left \n");
    printf("\t \t \t traffic arrival rate: %d \n", stats-> leftArrRate);
    printf("\t \t \t traffic light period: %d \n", stats->leftLightPeriod);
    printf("\t \t from right: \n");
    printf("\t \t \t traffic arrival rate: %d \n", stats-> rightArrRate);
    printf("\t \t \t traffic light period: %d \n", stats->rightLightPeriod);
    printf("\t Results (average over 100 runs): \n");
    printf("\t \t from left: \n");
    printf("\t \t \t number of vehicles: %d \n", stats-> numberOfVehiclesLeft / 100);
    printf("\t \t \t average waiting time: %d \n", stats-> avrgTimeLeft / stats->numberOfVehiclesLeft );
    printf("\t \t \t maximum waiting time: %d \n", stats->maxWaitTimeLeft);
    printf("\t \t \t clearance time: %d \n", stats-> clearanceTimeLeft);
    printf("\t \t from right: \n");
    printf("\t \t \t number of vehicles: %d \n", stats-> numberOfVehiclesRight / 100);
    printf("\t \t \t average waiting time: %d \n", stats-> avrgTimeRight / stats->numberOfVehiclesRight );
    printf("\t \t \t maximum waiting time: %d \n", stats->maxWaitTimeRight);
    printf("\t \t \t clearance time: %d \n", stats-> clearanceTimeRight);
    printf("\n");
}
               
