#include <stdio.h>
#include <string.h>

/* HackerRank-compatible solution function. */
char *timeConversion(char *s)
{
    static char converted[9];
    int hour;
    char period[3];

    sscanf(s, "%2d:%*2d:%*2d%2s", &hour, period);

    if (strcmp(period, "AM") == 0)
    {
        if (hour == 12)
        {
            hour = 0;
        }
    }
    else if (hour != 12)
    {
        hour += 12;
    }

    snprintf(converted, sizeof(converted), "%02d:%c%c:%c%c",
             hour, s[3], s[4], s[6], s[7]);
    return converted;
}

int main(void)
{
    char typical_case[] = "07:05:45PM";
    char edge_case[] = "12:00:00AM";

    printf("Test Case 1 - Typical Case\n");
    printf("Actual result: %s\n", timeConversion(typical_case));
    printf("Expected result: 19:05:45\n\n");

    printf("Test Case 2 - Edge Case\n");
    printf("Actual result: %s\n", timeConversion(edge_case));
    printf("Expected result: 00:00:00\n");

    return 0;
}
