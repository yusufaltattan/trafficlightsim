#include <stdio.h>

struct statistics {
    int leftArrRate;
    int rightArrRate;

    int leftLightPeriod;
    int rightLightPeriod;

    int numberOfVehiclesLeft;
    int numberOfVehiclesRight;

    int avrgTimeLeft;
    int avrgTimeRight;

    int maxWaitTimeLeft;
    int maxWaitTimeRight;

    int clearanceTimeLeft;
    int clearanceTimeRight;
};

typedef struct statistics AVERAGE_STATS;

extern void printStatistics(AVERAGE_STATS *);
