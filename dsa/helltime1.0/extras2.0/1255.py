class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        from typing import Counter

        def get_score(w):
            res = 0
            for char in w:
                res += score[ord(char) - ord('a')]
            return res

        def can_form(w, letters_cnt):
            word_cnt = Counter(w)
            for char in word_cnt:
                if word_cnt[char] > letters_cnt[char]:
                    return False
            return True

        letters_cnt = Counter(letters)

        def func(idx):
            if idx == len(words):
                return 0

            res = func(idx+1)  # skip
            # now include
            if can_form(words[idx], letters_cnt):
                for char in words[idx]:
                    letters_cnt[char] -= 1
                res = max(res, get_score(words[idx]) + func(idx+1))
                for char in words[idx]:
                    letters_cnt[char] += 1  # backtrack

            return res

        return func(0)
