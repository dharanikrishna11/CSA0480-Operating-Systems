#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int priority;
};

int selectHighestPriorityProcess(struct Process processes[], int n) {
    int highestPriority = processes[0].priority;
    int selectedProcess = 0;

    for (int i = 1; i < n; i++) {
        if (processes[i].priority > highestPriority) {
            highestPriority = processes[i].priority;
            selectedProcess = i;
        }
    }

    return selectedProcess;
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        printf("Enter priority for process %d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].id = i + 1;
    }

    int selectedProcessIndex = selectHighestPriorityProcess(processes, n);

    printf("Selected process: Process %d with priority %d\n",
           processes[selectedProcessIndex].id, processes[selectedProcessIndex].priority);

    free(processes);

    return 0;
}
