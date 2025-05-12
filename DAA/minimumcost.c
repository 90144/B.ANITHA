#include <stdio.h>
#include <limits.h>

// Function to find the sum of frequencies from i to j
int sum(int freq[], int i, int j) {
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

// Function to construct the Optimal BST
int optimalBST(int keys[], int freq[], int n) {
    int cost[n][n];

    // cost[i][j] = Optimal cost of BST that can be built from keys[i] to keys[j]

    // Initialize cost for single key trees
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Now fill the cost matrix for chains of length 2 to n
    for (int L = 2; L <= n; L++) { // L is chain length
        for (int i = 0; i <= n - L; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++) {
                // cost when r is root
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);

                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    return cost[0][n - 1];
}

// Main function
int main() {
    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Minimum cost of Optimal BST is: %d\n", optimalBST(keys, freq, n));
    return 0;
}
