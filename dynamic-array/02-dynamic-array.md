# Dynamic Array

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The program stores `n` independent dynamic sequences. For a query, the sequence index is calculated using `(x ^ last_answer) % n`.

Type 1 appends a value to the selected sequence, growing that sequence when necessary. Type 2 reads the requested value, updates `last_answer`, and stores it in the result array.

## Complexity

Time Complexity: O(N + Q)  
Space Complexity: O(N)

## Local Test Cases

1. **Test Case 1 - Typical Case**
   - Queries: `[[1,0,5], [1,1,7], [1,0,3], [2,1,0], [2,1,1]]`
   - Expected output: `7 3`
2. **Test Case 2 - Edge Case**
   - Queries: `[[1,0,42], [2,0,0]]`
   - Expected output: `42`

## Notes

The `dynamicArray` function uses the HackerRank-compatible interface and returns a dynamically allocated result array. The caller is responsible for freeing that array; the local `main()` demonstrates this.
