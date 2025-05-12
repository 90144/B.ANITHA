#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// A job structure
typedef struct {
    char id[5];     // Job ID
    int deadline;   // Deadline of job
    int profit;     // Profit if job is done before or on deadline
} Job;

// Comparison function to sort jobs in descending order of profit
int compare(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

// Find maximum deadline
int findMaxDeadline(Job jobs[], int n) {
    int max = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    }
    return max;
}

// Job sequencing function
void jobSequencing(Job jobs[], int n) {
    // Sort jobs by descending profit
    qsort(jobs, n, sizeof(Job), compare);

    int maxDeadline = findMaxDeadline(jobs, n);

    // Time slots for jobs, initialized to -1 (empty)
    char slot[maxDeadline + 1][5];
    for (int i = 0; i <= maxDeadline; i++)
        strcpy(slot[i], "");

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot from job.deadline to 1
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (strcmp(slot[j], "") == 0) {
                strcpy(slot[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (int i = 1; i <= maxDeadline; i++) {
        if (strcmp(slot[i], "") != 0)
            printf("%s ", slot[i]);
    }
    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    int n;
    Job jobs[MAX];

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    printf("Enter Job ID, Deadline, Profit for each job:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", jobs[i].id, &jobs[i].deadline, &jobs[i].profit);
    }

    jobSequencing(jobs, n);

    return 0;
}
