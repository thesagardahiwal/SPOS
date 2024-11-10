#include <stdio.h>

int main() {
    int i, n, time, remainingProcesses, flag = 0, timeQuantum;
    int waitTime = 0, turnaroundTime = 0, arrivalTime[10], burstTime[10], remainingTime[10];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    remainingProcesses = n;

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &arrivalTime[i], &burstTime[i]);
        remainingTime[i] = burstTime[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    printf("\nProcess\t| Turnaround Time | Waiting Time\n");

    for (time = 0, i = 0; remainingProcesses != 0;) {
        if (remainingTime[i] <= timeQuantum && remainingTime[i] > 0) {
            time += remainingTime[i];
            remainingTime[i] = 0;
            flag = 1;
        } else if (remainingTime[i] > 0) {
            remainingTime[i] -= timeQuantum;
            time += timeQuantum;
        }

        if (remainingTime[i] == 0 && flag == 1) {
            remainingProcesses--;
            printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, time - arrivalTime[i], time - arrivalTime[i] - burstTime[i]);
            waitTime += time - arrivalTime[i] - burstTime[i];
            turnaroundTime += time - arrivalTime[i];
            flag = 0;
        }

        if (i == n - 1) {
            i = 0;
        } else if (arrivalTime[i + 1] <= time) {
            i++;
        } else {
            i = 0;
        }
    }

    printf("\nAverage Waiting Time = %f\n", (float)waitTime / n);
    printf("Average Turnaround Time = %f\n", (float)turnaroundTime / n);

    return 0;
}
