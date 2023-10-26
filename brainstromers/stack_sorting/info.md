# Stack Sorting Algorithm

```C++
Stack tempStack;
while (!isEmpty())
{
    int temp = peek();
    pop();

    while (!tempStack.isEmpty() && tempStack.peek() > temp)
    {
        push(tempStack.peek());
        tempStack.pop();
    }
    tempStack.push(temp);
}
while (!tempStack.isEmpty())
{
    push(tempStack.peek());
    tempStack.pop();
}
```

## Step-by-Step Explanation

1. So the algorithms goes like that: First you create a `tempStack` and it should be empty.
2. Then if the `tempStack` is empty push the `peek()` value of the `originalStack` to the `tempStack` and `pop()` the `peek()` value from the `originalStack`.
3. If the `tempStack` is not empty store the `peek()` value of `originalStack` into `temp` variable. Enter into the while loop and check for two conditions:
   - If the `tempStack.isEmpty() is not Empty` &&
   - If the `tempStack.peek()` value is greater than the `peek()` value of `originalStack` i.e., `temp`.
4. Inside the while loop if the above two conditions are true then `push` the `tempStack.peek()` value to to `originalStack` and `tempStack.pop()`.
5. Continue with the inner while loop till the conditions are true.
6. When the while loop breaks add `temp` to the `tempStack` and continue with the outer loop.
7. Follow this process till the `originalStack` is empty. Once that is done `tempStack` will contain the elements into `Higher to Lower` manner. We can get all the elements into ascending order by pushing the elements from `tempStack` to the `originalStack` again one at a time.
