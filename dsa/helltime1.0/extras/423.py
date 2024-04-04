class Solution:
    def originalDigits(self, s: str) -> str:
        digit_count = [0] * 10
        count = Counter(s)
        digit_count[0] = count['z']
        digit_count[2] = count['w']
        digit_count[4] = count['u']
        digit_count[6] = count['x']
        digit_count[8] = count['g']
        digit_count[1] = count['o'] - digit_count[0] - digit_count[2] - digit_count[4]
        digit_count[3] = count['h'] - digit_count[8] 
        digit_count[5] = count['f'] - digit_count[4]
        digit_count[7] = count['v'] - digit_count[5]
        digit_count[9] = count['i'] - digit_count[5] - digit_count[6] - digit_count[8]
        ans = []
        ans = [ str(i) * digit_count[i] for i in range(10)]
        return "".join(ans)
