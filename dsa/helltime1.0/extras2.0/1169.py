class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:

        def cond_func(idx, t, x):
            nonlocal time
            for key, val in time.items():
                if idx != key and abs(x - val) <= 60:
                    if t[0] == transactions[key].split(',')[0] and t[3] != transactions[key].split(',')[3]:
                        return True
            return False

        out = []
        time = {}

        for idx, tx in enumerate(transactions):
            t = tx.split(',')
            time[idx] = int(t[1])

        for idx, tx in enumerate(transactions):
            t = tx.split(',')
            if int(t[2]) > 1000 or cond_func(idx, t, int(t[1])):
                out.append(tx)

        return out
