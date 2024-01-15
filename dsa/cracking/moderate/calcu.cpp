// 26. **Calculator:** Given an arithmetic equation consisting of positive integers, +, -, * and / (no parentheses), compute the result.

// Example:
// Input: 2*3+5/6*3+15
// Output: 23.5
#include <iostream>
#include <vector>
#include <string>
double calculateExpression(std::vector<std::string> &ex)
{
    while (ex.size() > 1)
    {
        for (int i = 0; i < ex.size(); ++i)
            if (ex[i] == "/")
            {
                double value = std::stod(ex[i - 1]) / std::stod(ex[i + 1]);
                ex.insert(ex.begin() + i - 1, std::to_string(value));
                ex.erase(ex.begin() + i, ex.begin() + i + 3);
            }
        for (int i = 0; i < ex.size(); ++i)
            if (ex[i] == "*")
            {
                double value = std::stod(ex[i - 1]) * std::stod(ex[i + 1]);
                ex.insert(ex.begin() + i - 1, std::to_string(value));
                ex.erase(ex.begin() + i, ex.begin() + i + 3);
            }
        for (int i = 0; i < ex.size(); ++i)
            if (ex[i] == "+")
            {
                double value = std::stod(ex[i - 1]) + std::stod(ex[i + 1]);
                ex.insert(ex.begin() + i - 1, std::to_string(value));
                ex.erase(ex.begin() + i, ex.begin() + i + 3);
            }
        for (int i = 0; i < ex.size(); ++i)
            if (ex[i] == "-")
            {
                double value = std::stod(ex[i - 1]) - std::stod(ex[i + 1]);
                ex.insert(ex.begin() + i - 1, std::to_string(value));
                ex.erase(ex.begin() + i, ex.begin() + i + 3);
            }
    }
    double result = std::stod(ex[0]);
    return result;
}
int main()
{
    std::string expression = "8*2+6/3-4*2+10/2";
    std::string container = "";
    std::vector<std::string> ex;
    for (int i = 0; i <= expression.length(); ++i)
        if (expression[i] == '*' || expression[i] == '+' || expression[i] == '-' || expression[i] == '/')
        {
            ex.push_back(container);
            ex.push_back(std::string(1, expression[i]));
            container = "";
        }
        else
        {
            container += std::string(1, expression[i]);
            if (i == expression.length())
                ex.push_back(container);
        }
    std::cout << calculateExpression(ex);
    return 0;
}