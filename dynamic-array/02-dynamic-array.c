#include <stdio.h>
#include <stdlib.h>

/* HackerRank-compatible solution function. */
int *dynamicArray(int n, int queries_rows, int queries_columns, int **queries, int *result_count)
{
    int **sequences = calloc((size_t)n, sizeof(*sequences));
    int *sizes = calloc((size_t)n, sizeof(*sizes));
    int *capacities = calloc((size_t)n, sizeof(*capacities));
    int *answers = malloc((size_t)queries_rows * sizeof(*answers));
    int last_answer = 0;
    int answer_index = 0;

    (void)queries_columns;

    for (int query_index = 0; query_index < queries_rows; query_index++)
    {
        int query_type = queries[query_index][0];
        int x = queries[query_index][1];
        int y = queries[query_index][2];
        int sequence_index = (x ^ last_answer) % n;

        if (query_type == 1)
        {
            if (sizes[sequence_index] == capacities[sequence_index])
            {
                capacities[sequence_index] = capacities[sequence_index] == 0
                    ? 1
                    : capacities[sequence_index] * 2;
                sequences[sequence_index] = realloc(
                    sequences[sequence_index],
                    (size_t)capacities[sequence_index] * sizeof(int));
            }
            sequences[sequence_index][sizes[sequence_index]++] = y;
        }
        else if (query_type == 2)
        {
            last_answer = sequences[sequence_index][y % sizes[sequence_index]];
            answers[answer_index++] = last_answer;
        }
    }

    for (int sequence_index = 0; sequence_index < n; sequence_index++)
    {
        free(sequences[sequence_index]);
    }
    free(sequences);
    free(sizes);
    free(capacities);

    *result_count = answer_index;
    return answers;
}

static void print_results(const char *label, int *results, int count, const int *expected)
{
    printf("%s\nActual result: ", label);
    for (int index = 0; index < count; index++)
    {
        printf("%d%s", results[index], index + 1 == count ? "" : " ");
    }
    printf("\nExpected result: ");
    for (int index = 0; index < count; index++)
    {
        printf("%d%s", expected[index], index + 1 == count ? "" : " ");
    }
    printf("\n\n");
}

int main(void)
{
    int typical_queries_data[][3] = {
        {1, 0, 5}, {1, 1, 7}, {1, 0, 3},
        {2, 1, 0}, {2, 1, 1}
    };
    int edge_queries_data[][3] = {
        {1, 0, 42}, {2, 0, 0}
    };
    int *typical_queries[5];
    int *edge_queries[2];
    int expected_typical[] = {7, 3};
    int expected_edge[] = {42};
    int result_count;
    int *results;

    for (int index = 0; index < 5; index++)
    {
        typical_queries[index] = typical_queries_data[index];
    }
    for (int index = 0; index < 2; index++)
    {
        edge_queries[index] = edge_queries_data[index];
    }

    results = dynamicArray(2, 5, 3, typical_queries, &result_count);
    print_results("Test Case 1 - Typical Case", results, result_count, expected_typical);
    free(results);

    results = dynamicArray(1, 2, 3, edge_queries, &result_count);
    print_results("Test Case 2 - Edge Case", results, result_count, expected_edge);
    free(results);

    return 0;
}
