class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        
        words = sentence.split()
        hashset = set(dictionary)

        def process(word):
            nonlocal hashset

            for i in range(len(word)):
                root = word[:i]
                if root in hashset:
                    return root
            return word

        
        for i in range(len(words)):
            words[i] = process(words[i])
        
        return " ".join(words)

        
