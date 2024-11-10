#include <stdio.h>

int main() {
    int n, i, waitTime = 0, turnaroundTime = 0;
    int arrivalTime[10], burstTime[10], completionTime[10], startTime[10], waitingTime[10], tat[10];
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
    }

    printf("\nProcess\t| Turnaround Time | Waiting Time\n");

    for (i = 0; i < n; i++) {
        if (i == 0) {
            startTime[i] = arrivalTime[i];  
        } else {
            startTime[i] = (completionTime[i - 1] > arrivalTime[i]) ? completionTime[i - 1] : arrivalTime[i];
        }
        
        completionTime[i] = startTime[i] + burstTime[i]; 
        tat[i] = completionTime[i] - arrivalTime[i];     
        waitingTime[i] = tat[i] - burstTime[i];          
        
        waitTime += waitingTime[i];
        turnaroundTime += tat[i];

        printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, tat[i], waitingTime[i]);
    }

    printf("\nAverage Waiting Time = %f\n", (float)waitTime / n);
    printf("Average Turnaround Time = %f\n", (float)turnaroundTime / n);

    return 0;
}
