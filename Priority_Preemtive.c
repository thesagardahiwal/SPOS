#include <stdio.h>

int main() {
    int p[20], bt[20], pri[20], rt[20], wt[20], tat[20], n, i, time, smallest, count = 0;
    float wtavg = 0, tatavg = 0;

    printf("\n *** Preemptive Priority Scheduling Algorithm ***\n");
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter the Burst Time and Priority of Process %d: ", i);
        scanf("%d %d", &bt[i], &pri[i]);
        rt[i] = bt[i]; 
    }

    pri[19] = 9999;
    
    for (time = 0; count != n; time++) {
        smallest = 19;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && pri[i] < pri[smallest]) {
                smallest = i;
            }
        }

        rt[smallest]--;  

        if (rt[smallest] == 0) {
            count++;
            tat[smallest] = time + 1;  
            wt[smallest] = tat[smallest] - bt[smallest]; 
            wtavg += wt[smallest];
            tatavg += tat[smallest];
        }
    }

    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time is --- %f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %f\n", tatavg / n);

    return 0;
}
