#include "queue.c"
#include "stats.c"
#include <time.h>
#include <string.h>

typedef enum { Green, Red } boolean;

int random_number(int min_num, int max_num){
    int result=0,low_num=0,hi_num=0;
    if(min_num<max_num){
    low_num=min_num;
    hi_num=max_num+1;
    }else{
    low_num=max_num+1;
    hi_num=min_num;
    }
    result = (rand()%(hi_num-low_num+1))+low_num;
    return result;
}



int sim(int leftProb, int rightProb, int leftCarsTime, int rightCarsTime) {   
    
    AVERAGE_STATS *stats = NULL;
    stats = (AVERAGE_STATS *) malloc(sizeof(AVERAGE_STATS));
    
    stats->leftArrRate = leftProb;
    stats->rightArrRate = rightProb;
    stats->leftLightPeriod = leftCarsTime;
    stats->rightLightPeriod = rightCarsTime;
 
    int h;  
    for (h=0; h < 100; h++ ) { 

    queue leftCars;
    queue rightCars;

    init_queue(&leftCars);
    init_queue(&rightCars);

    boolean leftLight, rightLight;
    leftLight = Green;
    rightLight = Red;
    srand(time(NULL));
    unsigned int arrivalRate = 2;
    unsigned int noOfLeftCars = 0;
    unsigned int noOfRightCars = 0;
    unsigned int iterations;
    unsigned int dequeuePileLeft = 0;
    unsigned int dequeuePileRight = 0;
    for(iterations = 0; iterations < 2000; iterations++){
        stats->avrgTimeLeft++;
        stats->avrgTimeRight++;
        int t;
        if (iterations < 500) {
        int x = random_number(0, leftProb);
        int y = random_number(0, rightProb);
            if (iterations % rightCarsTime  == 0) {
                if(leftLight == Green && rightLight == Red) {
                    leftLight = Red;
                    rightLight = Green;
            } else if (iterations % leftCarsTime == 0){
                leftLight = Green;
                rightLight = Red;
            }
        }
        else {
            if(x <= 1) {
                enqueue(&leftCars, 1);
                noOfLeftCars++;
                stats->numberOfVehiclesLeft++;
            } 
            if(y <= 1) {
                enqueue(&rightCars, 1);
                noOfRightCars++;
                stats->numberOfVehiclesRight++;
            }
        }
            if(leftLight == Green && rightLight == Red) {
                    if((t = dequeue(&leftCars)) != QUEUE_EMPTY) {
                    dequeue(&leftCars);
                    dequeuePileLeft++;
                }
            }
            else if(rightLight == Green && leftLight == Red) {
                if ((t = dequeue(&rightCars)) != QUEUE_EMPTY) {
                    dequeue(&rightCars);
                    dequeuePileRight++;
                }
            }
        }
        if (iterations >500) {
            if (iterations % 5 == 0) {
                 if(leftLight == Red && rightLight == Green) {
                    leftLight = Green;
                    rightLight = Red;
                 } else {
                    leftLight = Red;
                    rightLight = Green;
                 }
            }
            if (noOfLeftCars != dequeuePileLeft) {
                if(leftLight == Green && rightLight == Red) {
                    dequeue(&leftCars);
                    dequeuePileLeft++;
                    stats->avrgTimeLeft++;
                    stats->clearanceTimeLeft++;
                    stats->maxWaitTimeLeft++;
                }
            }
            if (dequeuePileRight != noOfRightCars) {
                if(rightLight == Green && leftLight == Red) {
                    dequeue(&rightCars);
                    dequeuePileRight++;
                    stats->avrgTimeRight++;
                    stats->clearanceTimeRight++;
                    stats->maxWaitTimeRight++;
                }
            }
            if((dequeuePileRight == noOfRightCars) && (dequeuePileLeft == noOfLeftCars)) {        
                    break;
            }

       }
   }
   }
   printStatistics(stats);
   free(stats);
}
 
runOneSimulation(int leftProb, int rightProb, int leftCarsTime,int rightCarsTime) {
    
    sim(leftProb, rightProb, leftCarsTime, rightCarsTime); 
}
