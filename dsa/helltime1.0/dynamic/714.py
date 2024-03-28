class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        cash, hold = 0, -prices[0]
        for price in prices[1:]:
            cash, hold = max(cash, hold + price - fee), max(hold, cash - price)
        return cash