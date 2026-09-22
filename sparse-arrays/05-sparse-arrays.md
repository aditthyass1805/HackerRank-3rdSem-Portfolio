# Sparse Arrays

## HackerRank

[HackerRank problem URL]

## Difficulty

Medium

## Approach

The input strings are counted once in a hash table. Each distinct string is stored with its frequency, so repeated values do not require repeated full scans.

Each query performs a hash lookup and returns the stored frequency, or zero when the query was not present. Separate chaining handles hash collisions.

## Complexity

Time Complexity: O(N + Q)  
Space Complexity: O(N)

## Local Test Cases

1. **Test Case 1 - Typical Case**
   - Strings: `["aba", "baba", "aba", "xzxb"]`
   - Queries: `["aba", "xzxb", "ab"]`
   - Expected output: `2 1 0`
2. **Test Case 2 - Edge Case**
   - Strings: `["hello"]`
   - Queries: `["hello", "world"]`
   - Expected output: `1 0`

## Notes

The `matchingStrings` function uses a hash table with separate chaining and returns a dynamically allocated result array. The local `main()` frees that array after printing the results. The hash table is also fully freed before the function returns.
