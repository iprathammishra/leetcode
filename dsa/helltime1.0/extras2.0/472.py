class Solution:
    def findAllConcatenatedWordsInADict(self, words: List[str]) -> List[str]:
        
        words = set(words)

        @cache
        def dfs(word):
            
            for i in range(len(word)):
                prefix = word[: i]
                suffix = word[i: ]
                if ((prefix in words and suffix in words) or (prefix in words and dfs(suffix))):
                    return True
            return False

        res = []
        for w in words:
            if dfs(w):
                res.append(w)
        
        return res
