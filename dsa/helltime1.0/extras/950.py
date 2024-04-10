class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        queue = deque()
        for d in sorted(deck, reverse=True):
            if queue:
                queue.appendleft(queue.pop())
            queue.appendleft(d)
        return list(queue)
