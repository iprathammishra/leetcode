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
