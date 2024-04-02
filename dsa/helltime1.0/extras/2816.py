class Solution:
    def doubleIt(self, head: Optional[ListNode]) -> Optional[ListNode]:
        sys.set_int_max_str_digits(0)
        store = []
        temp = head
        while temp:
            store.append(str(temp.val))
            temp = temp.next
        double_store = [int(char) for char in str(int("".join(store)) * 2)]
        new_head = None
        tail = None
        for ds in double_store:
            newnode = ListNode(ds)
            if new_head is None:
                new_head = newnode
                tail = newnode
            else:
                tail.next = newnode
                tail = newnode
        return new_head
