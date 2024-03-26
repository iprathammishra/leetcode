class Trie:
    def __init__(self):
        self.children = [None] * 26
        self.is_end_of_word = False

    def insert(self, word: str) -> None:
        """Inserts a word into the trie."""
        node = self
        for char in word:
            index = ord(char) - ord('a')
            if node.children[index] is None:
                node.children[index] = Trie()
            node = node.children[index]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """Searches for a word in the trie."""
        node = self._search_prefix(word)
        return node is not None and node.is_end_of_word

    def startsWith(self, prefix: str) -> bool:
        """Returns if there is any word in the trie that starts with the given prefix."""
        node = self._search_prefix(prefix)
        return node is not None

    def _search_prefix(self, prefix: str):
        """Searches for a node in the trie that represents the given prefix."""
        node = self
        for char in prefix:
            index = ord(char) - ord('a')
            if node.children[index] is None:
                return None
            node = node.children[index]
        return node
