#include <stdio.h>
#include <stdlib.h>

struct Process {
    int id;
    int arrivalTime;
    int executionTime;
};

void schedule(struct Process *processes, int n) {
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].executionTime > processes[j + 1].executionTime) {
              
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    printf("Scheduled Order:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d (Execution Time: %d)\n", processes[i].id, processes[i].executionTime);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for Process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter execution time for Process %d: ", i + 1);
        scanf("%d", &processes[i].executionTime);
    }

    schedule(processes, n);

    free(processes);

    return 0;
}
