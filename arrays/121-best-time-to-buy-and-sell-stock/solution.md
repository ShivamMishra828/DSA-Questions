# Best Time to Buy and Sell Stock (Question 121)

## Problem Statement

[Leetcode Problem](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`-th day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

### Constraints

-   1 ≤ `prices.length` ≤ 10^5
-   0 ≤ `prices[i]` ≤ 10^4

## Solution

```java
class Solution {
    public int maxProfit(int[] prices) {
        int buyPrice = Integer.MAX_VALUE;  // Initialize with the highest possible value
        int maxProfit = 0;  // Initialize max profit to 0 as no transactions have been made

        // Iterate through the array of prices
        for(int i = 0; i < prices.length; i++) {
            if(buyPrice < prices[i]) {
                // Calculate profit if the stock is sold today
                int profit = prices[i] - buyPrice;
                // Update maxProfit if the current profit is higher
                if(profit > maxProfit) {
                    maxProfit = profit;
                }
            }
            else {
                // Update the buy price to the current day price if it's lower
                buyPrice = prices[i];
            }
        }
        return maxProfit;  // Return the maximum profit that can be achieved
    }
}
```

## Explanation

-   buyPrice: Tracks the minimum price to buy the stock, initialized to Integer.MAX_VALUE.
-   maxProfit: Tracks the maximum profit possible at each day, initialized to 0.

The logic iterates through each day's price:

-   If the current price is higher than the buyPrice, it calculates the profit from buying at buyPrice and selling at the current price. If this profit is higher than the current maxProfit, the maxProfit is updated.
-   If the current price is lower than buyPrice, the buyPrice is updated to the current price, as we want to buy at the lowest possible price.

Finally, it returns the maxProfit, which is the maximum possible profit.

### Important Concepts

-   Tracking the Minimum Price: By updating the buyPrice whenever a lower price is encountered, we ensure that we always calculate the profit from the lowest possible price.
-   Single Transaction: We are only allowed to make one transaction (one buy and one sell), so the algorithm focuses on finding the best possible day to buy and the best future day to sell.

### Time Complexity

O(n): We traverse the array once to calculate the maximum profit, where n is the number of days.

### Space Complexity

O(1): We use a constant amount of extra space (for buyPrice and maxProfit).

### Edge Cases

-   If the prices are strictly decreasing, no profit can be made, and the result should be 0.
-   If the prices are all the same, no profit can be made, and the result should be 0.

### Dry Run

Input: prices = [7, 1, 5, 3, 6, 4]

1. Initial State:

-   buyPrice = Integer.MAX_VALUE
-   maxProfit = 0

2. Iteration:

-   Day 1 (prices[0] = 7): buyPrice = 7, maxProfit = 0
-   Day 2 (prices[1] = 1): buyPrice = 1, maxProfit = 0
-   Day 3 (prices[2] = 5): Profit = 5 - 1 = 4, maxProfit = 4
-   Day 4 (prices[3] = 3): Profit = 3 - 1 = 2, maxProfit = 4 (no change)
-   Day 5 (prices[4] = 6): Profit = 6 - 1 = 5, maxProfit = 5
-   Day 6 (prices[5] = 4): Profit = 4 - 1 = 3, maxProfit = 5 (no change)

Final Answer: 5 (Buy at 1 and sell at 6).
