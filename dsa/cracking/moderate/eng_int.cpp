// 8. **English Int:** Given any integer, print an English phrase that describes the integer (e.g., "One Thousand, Two Hundred Thirty Four").
#include <iostream>
#include <string>
#include <vector>
std::string dealWith3(int n)
{
    std::string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",};
    std::string teens[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::string tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    int hundred = n / 100;
    int ten = (n % 100) / 10;
    int one = n % 10;

    std::string result;

    if (hundred > 0)
        result += ones[hundred] + " Hundred ";
    if (ten == 1)
        result += teens[one] + " ";
    else if (ten > 1)
        {result += tens[ten] + " ";
        if (one > 0)
            result += ones[one] + " ";}
    else if (one > 0)
        result += ones[one] + " ";
    return result;

}
std::string engInt(int n)
{
    if (n == 0)
        return "Zero";
    std::string scale[] = {"", "Thousand", "Million", "Billion"};
    int i = 0;
    std::vector<std::string> groups;
    while (n > 0)
    {
        int threeDigitNumber = n % 1000;
        if (threeDigitNumber != 0) 
            groups.push_back(dealWith3(threeDigitNumber) + scale[i]);
        n /= 1000;
        i++;
    }

    std::string result;
    for (int j = groups.size() - 1; j >= 0; j--)
        result += groups[j] + " ";
    return result;
}
int main()
{
    std::cout << engInt(12034358) << std::endl;
    return 0;
}

// https://chat.openai.com/share/e06f4aeb-1284-4cb3-a75e-b221cae1e44d