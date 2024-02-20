#include <stdio.h>
#include <stdlib.h>

// Structure to store the value and weight of an item
struct Item {
    int value;
    int weight;
};

// Function to compare two items based on their value/weight ratio
int cmp(const void* a, const void* b) {
    struct Item* item1 = (struct Item*)a;
    struct Item* item2 = (struct Item*)b;
    double r1 = (double)item1->value / (double)item1->weight;
    double r2 = (double)item2->value / (double)item2->weight;
    if (r1 < r2)
        return 1;
    else if (r1 > r2)
        return -1;
    else
        return 0;
}

// Function to solve the fractional knapsack problem using greedy algorithm
double knapsack_frac(int W, struct Item* items, int n) {
    qsort(items, n, sizeof(struct Item), cmp);

    int i;
    double value = 0.0;
    for (i = 0; i < n; i++) {
        if (W == 0)
            return value;
        else if (items[i].weight <= W) {
            W -= items[i].weight;
            value += items[i].value;
        }
        else {
            value += items[i].value * ((double)W / (double)items[i].weight);
            W = 0;
        }
    }

    return value;
}

// Driver code to test the implementation
int main() {
    int W = 50;
    struct Item items[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int n = sizeof(items) / sizeof(struct Item);
    double max_value = knapsack_frac(W, items, n);
    printf("Maximum value: %.2lf", max_value);
    return 0;
}
