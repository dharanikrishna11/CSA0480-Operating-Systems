#include <stdio.h>
#include <stdlib.h>
struct Process {
    int id;
    int priority;
    int burstTime;
    int remainingTime;
};
int selectHighestPriorityProcess(struct Process processes[], int n) {
    int highestPriority = processes[0].priority;
    int selectedProcess = 0;

    for (int i = 1; i < n; i++) {
        if (processes[i].priority < highestPriority && processes[i].remainingTime > 0) {
            highestPriority = processes[i].priority;
            selectedProcess = i;
        }
    }

    return selectedProcess;
}

void priorityScheduling(struct Process processes[], int n) {
    int currentTime = 0;

    while (1) {
        int selectedProcessIndex = selectHighestPriorityProcess(processes, n);

        if (processes[selectedProcessIndex].remainingTime <= 0) {
            break;
        }
        printf("Time %d: Executing process %d (Priority: %d)\n", currentTime,
               processes[selectedProcessIndex].id, processes[selectedProcessIndex].priority);

        processes[selectedProcessIndex].remainingTime--;

        currentTime++;
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter priority for process %d: ", processes[i].id);
        scanf("%d", &processes[i].priority);
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    priorityScheduling(processes, n);

    free(processes);

    return 0;
}
