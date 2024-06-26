class MyHashSet:

    def __init__(self):
        self.hlist = []

    def add(self, key: int) -> None:
        if key not in self.hlist:
            self.hlist.append(key)

    def remove(self, key: int) -> None:
        if self.contains(key):
            self.hlist.remove(key)

    def contains(self, key: int) -> bool:
        return key in self.hlist


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)
