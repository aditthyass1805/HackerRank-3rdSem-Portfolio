# Diagonal Difference

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The primary diagonal uses positions where the row and column indexes are equal. The secondary diagonal starts at the top-right and uses column index `N - 1 - row`.

One pass through the rows is enough to add both diagonal values. The absolute difference between the two sums is returned.

## Complexity

Time Complexity: O(N)  
Space Complexity: O(1)

## Local Test Cases

1. **Test Case 1 - Typical Case**
   - Matrix: `[[11, 2, 4], [4, 5, 6], [10, 8, -12]]`
   - Expected output: `10`
2. **Test Case 2 - Edge Case**
   - Matrix: `[[5, 0, 0], [0, 5, 0], [0, 0, 5]]`
   - Expected output: `15`

## Notes

The `diagonalDifference` function matches the main logic expected by HackerRank. The local `main()` function can be removed or adapted when submitting through HackerRank's editor.
