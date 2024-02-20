
#include <stdio.h>
#include<stdlib.h>

// Define maximum number of jobs and maximum deadline
#define MAX_JOBS 100
#define MAX_DEADLINE 100

// Define structure for each job with its profit and deadline
struct Job {
    int profit;
    int deadline;
};

// Function to compare jobs based on their profit in non-increasing order
int compare_jobs(const void* a, const void* b) {
    return (*(struct Job*)b).profit - (*(struct Job*)a).profit;
}

// Function to perform job scheduling with deadline
void job_scheduling(struct Job jobs[], int n) {
    // Sort the jobs in non-increasing order based on their profit
    qsort(jobs, n, sizeof(struct Job), compare_jobs);

    // Create an array to store the maximum profit that can be earned
    // for each deadline (initialized to 0)
    int max_profit[MAX_DEADLINE + 1] = {0};

    // For each job, find the latest deadline before which it can be scheduled
    // and add its profit to the corresponding entry in the max_profit array
    for (int i = 0; i < n; i++) {
        int deadline = jobs[i].deadline;
        while (deadline > 0 && max_profit[deadline] != 0) {
            deadline--;
        }
        if (deadline > 0) {
            max_profit[deadline] = jobs[i].profit;
        }
    }

    // Calculate the total profit that can be earned
    int total_profit = 0;
    for (int i = 1; i <= MAX_DEADLINE; i++) {
        total_profit += max_profit[i];
    }

    // Print the maximum profit and the deadlines for each job
    printf("Maximum profit: %d\n", total_profit);
    printf("Deadlines:");
    for (int i = 1; i <= MAX_DEADLINE; i++) {
        if (max_profit[i] != 0) {
            printf(" %d", i);
        }
    }
    printf("\n");
}

// Driver code to test the job_scheduling function
int main() {
    // Example jobs with their profits and deadlines
    struct Job jobs[] = {{35, 3}, {30, 4}, {25, 4}, {20, 2}, {15, 3}, {12, 1}, {5, 2}};

    // Number of jobs
    int n = sizeof(jobs) / sizeof(jobs[0]);

    // Perform job scheduling and print the results
    job_scheduling(jobs, n);

    return 0;
}


/*
 n this code, the Job structure is used to store the profit and deadline of each job. The compare_jobs function is used to compare two jobs based on their profit in non-increasing order, which is required for sorting the jobs. The job_scheduling function performs the actual job scheduling by sorting the jobs based on their profit, finding the latest deadline before which each job can be scheduled, and calculating the maximum profit that can be earned for each deadline. Finally, the total profit and the deadlines for each job are printed. The main function defines an example set of jobs and calls the job_scheduling function to perform job scheduling and print the results.
 */
