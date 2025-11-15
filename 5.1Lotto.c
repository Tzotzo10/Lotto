#include <stdio.h>
#include <stdlib.h>

// Selection Sort (ascending)
void SelectionS(int A[], int N) {
    int i, j, min, temp;
    for (i = 0; i < N - 1; i++) {
        min = i;
        for (j = i + 1; j < N; j++)
            if (A[j] < A[min])
                min = j;
        temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

// Factorial of n
int Factorial(int n) {
    int f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}

// Count even digits of a 5-digit encoded number
int plcx(int num) {
    int count = 0;
    for (int k = 0; k < 5; k++) {
        int digit = (num / (int)pow(10, 4 - k)) % 10;
        if (digit % 2 == 0) count++;
    }
    return count;
}

// Sum digits of a 5-digit encoded number
int sumy(int num) {
    int sum = 0;
    for (int k = 0; k < 5; k++) {
        int digit = (num / (int)pow(10, 4 - k)) % 10;
        sum += digit;
    }
    return sum;
}

// Compute digit frequency among digits 1–45 (simple version)
float Frequency(int num) {
    int count = 0;

    for (int k = 0; k < 5; k++) {
        int digit = (num / (int)pow(10, 4 - k)) % 10;

        if (digit >= 1 && digit <= 45)
            count++;
    }

    return (float)count / 5.0f;
}

// ---------------- Combination Generator -----------------

/* Generate all 5-number combinations (N choose 5) */
int GenerateCombinations(int A[], int N, int C[]) {
    int idx = 0;

    for (int a = 0; a < N - 4; a++)
    for (int b = a + 1; b < N - 3; b++)
    for (int c1 = b + 1; c1 < N - 2; c1++)
    for (int d = c1 + 1; d < N - 1; d++)
    for (int e = d + 1; e < N; e++) {
        // encode combination as 5-digit number
        int num = A[a]*10000 + A[b]*1000 + A[c1]*100 + A[d]*10 + A[e];
        C[idx++] = num;
    }

    return idx; // number of combinations
}

// ------------------------- MAIN -------------------------

int main() {
    int N;
    int A[45];       // input numbers
    int x1, x2;      // even-digit range
    int y1, y2;      // sum-of-digits range

    // Ask how many integers
    do {
        printf("How many integers? (5–45): ");
        scanf("%d", &N);
    } while (N < 5 || N > 45);

    // Read numbers
    for (int i = 0; i < N; i++) {
        do {
            printf("Enter number %d (1–45): ", i + 1);
            scanf("%d", &A[i]);
        } while (A[i] < 1 || A[i] > 45);
    }

    // Read even-digit filter
    do {
        printf("Enter X-range (x1 x2) for even-digit count: ");
        scanf("%d %d", &x1, &x2);
    } while (x1 < 0 || x2 > 5 || x1 > x2);

    // Read digit-sum filter
    do {
        printf("Enter Y-range (y1 y2) for digit sum: ");
        scanf("%d %d", &y1, &y2);
    } while (y1 < 5 || y2 > 45*5 || y1 > y2);


    // ----------- PROCESSING -----------

    SelectionS(A, N);   // sort the input numbers

    int C[200000];      // storage for combinations

    int total = GenerateCombinations(A, N, C);

    printf("\nGenerated %d combinations.\n", total);

    int validCount = 0;

    for (int i = 0; i < total; i++) {
        int num = C[i];

        int ev = plcx(num);
        int sm = sumy(num);
        float fr = Frequency(num);

        // Apply filters
        if (ev < x1 || ev > x2) continue;
        if (sm < y1 || sm > y2) continue;

        validCount++;

        printf("Combination: %d | Even=%d | Sum=%d | Freq=%.2f\n", num, ev, sm, fr);
    }

    printf("\nValid combinations: %d\n", validCount);

    return 0;
}
