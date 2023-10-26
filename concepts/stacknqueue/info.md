# Stack

The stack data structure is precisely what it sounds like: a stack of data. In certain types of problems, it can be favorable to store data in a stack rather than in an array.

A stack uses LIFO (last-in-first-out) ordering. That is, as in a stack of dinner plates, the most recent item added to the stack is ther first item to be removed.

It used the following operations:

- pop(): Remove the top item from the stack.
- push(item): Add an item to the top of the stack.
- peek(): Return the top of the stack.
- isEmpty(): Return true if and only of the stack is empty.

# Queue

A queue implements FIFO (first-in-first-out) ordering. As in a line or queue at a ticket stand, items are removed from the data structure in the same order that they are added.

It uses the operations:

- add(item): Add an item to the end of the list.
- remove(): Remove the first item in the list.
- peek(): Return the top of the queue.
- isEmpty(): Return true if and only if the queue is empty.

## Interview Questions

<!-- 1. **Three in One:** Describe how you could use a singly array to implement three stacks. -->

2. **Stack Min:** How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop, and min should all operate in O(1) time.

3. **Stack of Plates:** Imagine a (literal) stack of plates. If the stack gets too high, it might topple. Therefore, in real life, we would likely start a new stack when the previous stack exceeds some threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be composed of several stacks and should create a new stack once the previous one exceeds capacity. SetOfStacks.push() and SetOfStacks.pop() should behave identically to a single stack (that is, pop() should return the same values as it would if there were just a single stack).

Follow Up:
Implement a function popAt(int index) which performs a pop operation on a specific sub-stack.

4. **Queue via Stacks:** Implement a MyQueue class implements a queue using two stacks.

5. **Sort Stack:** Write a program to sort a stack such that the smallest items are on the top. You can use an additional temporary stack, but you may not copy the elements into any other data structure (such as an array). The stack supports the following operations: push, peek, and isEmpty.

6. **Animal Shelter:** An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter, or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of that type). They cannot select which specific animal they would like. Create the data structures to maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog, and dequeueCat. You may use the build-in LinkedList data structure.
