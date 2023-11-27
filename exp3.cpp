#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

void calculateTimes(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {

    waitingTime[0] = 0;

    turnaroundTime[0] = processes[0].burstTime;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;

        turnaroundTime[i] = waitingTime[i] + processes[i].burstTime;
    }
}

void calculateAverages(int waitingTime[], int turnaroundTime[], int n, float *avgWaitingTime, float *avgTurnaroundTime) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }

    *avgWaitingTime = (float)totalWaitingTime / n;
    *avgTurnaroundTime = (float)totalTurnaroundTime / n;
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *) malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrivalTime = 0;  
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }
    int *waitingTime = (int *)malloc(n * sizeof(int));
    int *turnaroundTime = (int *)malloc(n * sizeof(int));

    calculateTimes(processes, n, waitingTime, turnaroundTime);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].burstTime, waitingTime[i], turnaroundTime[i]);
    }

    float avgWaitingTime, avgTurnaroundTime;
    calculateAverages(waitingTime, turnaroundTime, n, &avgWaitingTime, &avgTurnaroundTime);

    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);

    free(processes);
    free(waitingTime);
    free(turnaroundTime);

    return 0;
}
