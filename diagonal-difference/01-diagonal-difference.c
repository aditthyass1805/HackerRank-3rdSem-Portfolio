#include <stdio.h>
#include <stdlib.h>

/* HackerRank-compatible solution function. */
int diagonalDifference(int arr_rows, int arr_columns, int **arr)
{
    int primary_diagonal = 0;
    int secondary_diagonal = 0;

    for (int index = 0; index < arr_rows; index++)
    {
        primary_diagonal += arr[index][index];
        secondary_diagonal += arr[index][arr_columns - 1 - index];
    }

    return abs(primary_diagonal - secondary_diagonal);
}

static void run_test_case(const char *label, int size, int values[][3], int expected)
{
    int *rows[3];

    for (int index = 0; index < size; index++)
    {
        rows[index] = values[index];
    }

    printf("%s\n", label);
    printf("Actual result: %d\n", diagonalDifference(size, size, rows));
    printf("Expected result: %d\n\n", expected);
}

int main(void)
{
    int typical_case[3][3] = {
        {11, 2, 4},
        {4, 5, 6},
        {10, 8, -12}
    };
    int edge_case[3][3] = {
        {5, 0, 0},
        {0, 5, 0},
        {0, 0, 5}
    };

    run_test_case("Test Case 1 - Typical Case", 3, typical_case, 15);
    run_test_case("Test Case 2 - Edge Case", 3, edge_case, 10);

    return 0;
}
