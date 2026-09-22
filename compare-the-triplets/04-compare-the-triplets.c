#include <stdio.h>

/* HackerRank-compatible solution function. */
int *compareTriplets(int a_count, int *a, int b_count, int *b, int *result_count)
{
    static int scores[2];
    int count = a_count < b_count ? a_count : b_count;

    scores[0] = 0;
    scores[1] = 0;

    for (int index = 0; index < count; index++)
    {
        if (a[index] > b[index])
        {
            scores[0]++;
        }
        else if (a[index] < b[index])
        {
            scores[1]++;
        }
    }

    *result_count = 2;
    return scores;
}

static void run_test_case(const char *label, int *a, int *b, int expected_alice, int expected_bob)
{
    int result_count;
    int *scores = compareTriplets(3, a, 3, b, &result_count);

    printf("%s\n", label);
    printf("Actual result: %d %d\n", scores[0], scores[1]);
    printf("Expected result: %d %d\n\n", expected_alice, expected_bob);
}

int main(void)
{
    int typical_alice[] = {5, 6, 7};
    int typical_bob[] = {3, 6, 10};
    int edge_alice[] = {1, 1, 1};
    int edge_bob[] = {1, 1, 1};

    run_test_case("Test Case 1 - Typical Case", typical_alice, typical_bob, 1, 1);
    run_test_case("Test Case 2 - Edge Case", edge_alice, edge_bob, 0, 0);

    return 0;
}
