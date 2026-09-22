# Time Conversion

## HackerRank

[HackerRank problem URL]

## Difficulty

Easy

## Approach

The last two characters identify whether the time is in the morning or evening. The hour is parsed from the first two characters.

For `12 AM`, the hour becomes `00`. For a PM hour other than `12`, twelve is added. The minutes and seconds are copied unchanged into the 24-hour result.

## Complexity

Time Complexity: O(1)  
Space Complexity: O(1)

## Local Test Cases

1. **Test Case 1 - Typical Case**
   - Input: `07:05:45PM`
   - Expected output: `19:05:45`
2. **Test Case 2 - Edge Case**
   - Input: `12:00:00AM`
   - Expected output: `00:00:00`

## Notes

The function returns a static character array so its result remains valid after the function returns. This is convenient for the HackerRank function interface and avoids requiring the caller to allocate the result buffer.
