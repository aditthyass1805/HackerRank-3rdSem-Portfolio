#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 200003

typedef struct Entry
{
    char *text;
    int count;
    struct Entry *next;
} Entry;

static unsigned long hash_string(const char *text)
{
    unsigned long hash = 5381;

    while (*text != '\0')
    {
        hash = ((hash << 5) + hash) + (unsigned char)*text;
        text++;
    }
    return hash % TABLE_SIZE;
}

static void add_string(Entry **table, const char *text)
{
    unsigned long index = hash_string(text);
    Entry *entry = table[index];

    while (entry != NULL)
    {
        if (strcmp(entry->text, text) == 0)
        {
            entry->count++;
            return;
        }
        entry = entry->next;
    }

    entry = malloc(sizeof(*entry));
    entry->text = malloc(strlen(text) + 1);
    strcpy(entry->text, text);
    entry->count = 1;
    entry->next = table[index];
    table[index] = entry;
}

static int get_count(Entry **table, const char *text)
{
    Entry *entry = table[hash_string(text)];

    while (entry != NULL)
    {
        if (strcmp(entry->text, text) == 0)
        {
            return entry->count;
        }
        entry = entry->next;
    }
    return 0;
}

static void free_table(Entry **table)
{
    for (int index = 0; index < TABLE_SIZE; index++)
    {
        Entry *entry = table[index];
        while (entry != NULL)
        {
            Entry *next = entry->next;
            free(entry->text);
            free(entry);
            entry = next;
        }
    }
    free(table);
}

/* HackerRank-compatible solution function. */
int *matchingStrings(int strings_count, char **strings, int queries_count,
                     char **queries, int *result_count)
{
    Entry **table = calloc(TABLE_SIZE, sizeof(*table));
    int *answers = malloc((size_t)queries_count * sizeof(*answers));

    for (int index = 0; index < strings_count; index++)
    {
        add_string(table, strings[index]);
    }
    for (int index = 0; index < queries_count; index++)
    {
        answers[index] = get_count(table, queries[index]);
    }

    free_table(table);
    *result_count = queries_count;
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
    char *typical_strings[] = {"aba", "baba", "aba", "xzxb"};
    char *typical_queries[] = {"aba", "xzxb", "ab"};
    char *edge_strings[] = {"hello"};
    char *edge_queries[] = {"hello", "world"};
    int expected_typical[] = {2, 1, 0};
    int expected_edge[] = {1, 0};
    int result_count;
    int *results;

    results = matchingStrings(4, typical_strings, 3, typical_queries, &result_count);
    print_results("Test Case 1 - Typical Case", results, result_count, expected_typical);
    free(results);

    results = matchingStrings(1, edge_strings, 2, edge_queries, &result_count);
    print_results("Test Case 2 - Edge Case", results, result_count, expected_edge);
    free(results);

    return 0;
}
