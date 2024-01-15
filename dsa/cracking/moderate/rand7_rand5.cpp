// 23. **Rand7 from Rand5:** Implement a method rand7() given rand5(). That is, given a method that generates a random number between 0 and 4 (inclusive), write a method that generates a random number between 0 and 6 (inclusive).
#include <iostream>
int rand5()
{
    return std::rand() % 5;
}
int rand7()
{
    int num;
    do
    {
        num = 5 * rand5() + rand5();
    } while (num >= 21);

    return num % 7;
}
int main()
{
    for (int i = 0; i <= 9; ++i)
        std::cout << rand7() << " ";
    return 0;
}

// https://chat.openai.com/share/867f91e2-5719-457c-82f9-cd1cb616f84c