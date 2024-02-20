#include <stdio.h>
#include <stdlib.h>

#define MAX_EVENTS 100

struct Event {
    int time;
    int is_departure;
};

int compare_events(const void *a, const void *b) {
    return (*(struct Event*)a).time - (*(struct Event*)b).time;
}

void train_scheduling(struct Event events[], int n) {
    // Sort the events in non-decreasing order based on their time
    qsort(events, n, sizeof(struct Event), compare_events);

    // Initialize variables
    int platforms_in_use = 0;
    int max_platforms = 0;

    // Iterate through the events and simulate the train schedule
    for (int i = 0; i < n; i++) {
        // If the current event is an arrival, increment the number of platforms in use
        if (!events[i].is_departure) {
            platforms_in_use++;
        }
        // If the current event is a departure, decrement the number of platforms in use
        else {
            platforms_in_use--;
        }
        // Update the maximum number of platforms needed
        if (platforms_in_use > max_platforms) {
            max_platforms = platforms_in_use;
        }
    }

    // Print the maximum platforms needed
    printf("Maximum platforms needed: %d\n", max_platforms);
}

int main() {
    // Example train schedule
    struct Event events[] = {{10, 0}, {20, 1}, {30, 0}, {40, 1}, {35, 0}, {45, 1}};

    // Number of events
    int n = sizeof(events) / sizeof(events[0]);

    // Perform train scheduling and print the results
    train_scheduling(events, n);

    return 0;
}
