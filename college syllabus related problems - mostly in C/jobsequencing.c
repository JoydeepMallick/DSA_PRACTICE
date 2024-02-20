
#include <stdio.h>
#include <stdlib.h>

struct job {
    int job_no;
    int start_time;
    int end_time;
};

// Compare function to sort jobs in decreasing order of end time
int cmpfunc(const void* a, const void* b) {
    const struct job* job1 = (const struct job*) a;
    const struct job* job2 = (const struct job*) b;
    return (job1->end_time - job2->end_time);//ascending
    //return (job2->end_time - job1->end_time);//decending
}

void printjobs(struct job jobs[], int n){
    int i = 0;
    printf("Job no.\tStart time End time\n");
    while(i < n){
        printf("%5d\t%5d\t%5d\n", jobs[i].job_no, jobs[i].start_time, jobs[i].end_time);
        i++;
    }
}

int max_jobs(struct job jobs[], int n) {
    int i, count = 0;
    int end_time[n]; // Array to store end time of jobs
    qsort(jobs, n, sizeof(struct job), cmpfunc); // Sort jobs in decreasing order of end time
    printf("\n\nSorted jobs in decending order of end date:-\n");
    printjobs(jobs, n);
    // Set the end time of the first job as the end time of the sequence
    end_time[0] = jobs[0].end_time;
    //first job selected as start always
    printf("Least end date job %d selected as start point\n", jobs[0].job_no);
    count++;

    // Check for each job if it can be included in the sequence
    for (i = 1; i < n; i++) {
        // Check if the start time of the job is after the end time of the previous job in the sequence
        if (jobs[i].start_time >= end_time[count - 1]) {
            end_time[count] = jobs[i].end_time;
            count++;
            printf("\nSelected job no. = %3d\n", jobs[i].job_no);
        }
    }
    return count;
}

int main() {
/*    struct job jobs[] = {
        {1, 0, 6},
        {2, 1, 4},
        {3, 3, 5},
        {4, 3, 8},
        {5, 4, 7},
        {6, 5, 9},
        {7, 6, 10}
    }; 
*/
    struct job jobs[] = {
        {1, 1, 3},
        {2, 3, 4},
        {3, 2, 5},
        {4, 4, 7},
        {5, 8, 9},
        {6, 7, 10},
        {7, 9, 11},
        {8, 9, 13}
    };

    int n = sizeof(jobs)/sizeof(jobs[0]);
    printf("\n\nEntered jobs :-\n");
    printjobs(jobs, n);
    int max_jobs_count = max_jobs(jobs, n);
    printf("Maximum number of jobs that can be done: %d\n", max_jobs_count);
    return 0;
}
