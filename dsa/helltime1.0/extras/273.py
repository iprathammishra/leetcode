class Solution:
    def __init__(self) -> None:
        self.below10 = ["", "One", "Two", "Three", "Four",
                        "Five", "Six", "Seven", "Eight", "Nine"]
        self.below20 = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                        "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        self.below100 = ["", "Ten", "Twenty", "Thirty", "Forty",
                         "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]

    def helper(self, num) -> str:
        res = ""
        if num < 10:
            res = self.below10[num]
        elif num < 20:
            res = self.below20[num-10]
        elif num < 100:
            res = self.below100[num//10] + \
                " " + self.helper(num % 10)
        elif num < 1000:
            res = self.helper(num//100) + \
                " Hundred " + self.helper(num % 100)
        elif num < 1000000:
            res = self.helper(num//1000) + \
                " Thousand " + self.helper(num % 1000)
        elif num < 1000000000:
            res = self.helper(num//1000000) + \
                " Million " + self.helper(num % 1000000)
        else:
            res = self.helper(num//1000000000) + " Billion " + \
                self.helper(num % 1000000000)
        return res.strip()

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        return self.helper(num)
