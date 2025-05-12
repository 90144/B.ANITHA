#include <stdio.h>

#define MAX 100

int n;                 // Number of elements
int target;            // Target sum
int set[MAX];          // Input set
int subset[MAX];       // To store current subset

// Function to print a valid subset
void printSubset(int size) {
    printf("{ ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("}\n");
}

// Recursive backtracking function
void sumOfSubsets(int index, int currentSum, int subsetSize) {
    if (currentSum == target) {
        printSubset(subsetSize);
        return;
    }

    for (int i = index; i < n; i++) {
        if (currentSum + set[i] <= target) {
            subset[subsetSize] = set[i];  // Include element
            sumOfSubsets(i + 1, currentSum + set[i], subsetSize + 1);
        }
    }
}

int main() {
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements in ascending order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d:\n", target);
    sumOfSubsets(0, 0, 0);

    return 0;
}
