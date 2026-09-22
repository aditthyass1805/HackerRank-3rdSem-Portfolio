# Compare the Triplets

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The corresponding elements in Alice's and Bob's triplets are compared one by one. A point is added to Alice when her value is larger, and a point is added to Bob when his value is larger.

Equal values do not add a point to either participant. The two scores are returned in the required order: Alice first and Bob second.

## Complexity

Time Complexity: O(1)  
Space Complexity: O(1)

## Local Test Cases

1. **Test Case 1 - Typical Case**
   - Alice: `[5, 6, 7]`; Bob: `[3, 6, 10]`
   - Expected output: `1 1`
2. **Test Case 2 - Edge Case**
   - Alice: `[1, 1, 1]`; Bob: `[1, 1, 1]`
   - Expected output: `0 0`

## Notes

The `compareTriplets` function returns a static two-element array, matching the common HackerRank C function interface. The local test harness prints the two scores.
