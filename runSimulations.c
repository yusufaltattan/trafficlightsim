#include "runOneSimulation.c"


int main() {
    int leftProb, rightProb, leftTime, rightTime;
    printf("Please Enter Left Cars Arrival Rate (The lower the number, the more cars arrive): \n");
    scanf("%d",&leftProb);
    printf("Please Enter Right Cars Arrival Rate (The lower the number, the more cars arrive): \n");
    scanf("%d", &rightProb);
    printf("Please Enter Left Traffic Light Period: \n");
    scanf("%d", &leftTime);
    printf("Please Enter Right Traffic Light Period: \n");
    scanf("%d", &rightTime);

    runOneSimulation(leftProb,rightProb,leftTime,rightTime);
}

