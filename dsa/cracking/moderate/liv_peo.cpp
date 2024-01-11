// 10. **Living People:** Given a list of people with their birth and death years, implement a method to compute the year with the most number of people alive. You assume that all people were born between 1900 and 2000 (inclusive). If a person was alive during any portion of that year, they should be included in that year's count. For example, Person (birth = 1908, death = 1909) is included in the counts for both 1908 and 1909.
#include <iostream>
#include <vector>
struct Person
{
    int birth;
    int death;
};
int livingPeople(const std::vector<Person>& people)
{
    int years[101] = {0};
    for (const Person& p: people)
        for (int i = p.birth; i <= p.death; ++i)
            ++years[i - 1900];

    int maxAliveYear = 1900;
    int maxAliveYearCount = years[0];

    for (int j = 1; j < 101; ++j)
        if (years[j] > maxAliveYearCount)
            maxAliveYear = 1900 + j;
    return maxAliveYear;
}
int main()
{
    std::vector<Person> people = {
        {1900, 1950},
        {1910, 1967},
        {1940, 1990},
    };
    std::cout << livingPeople(people) << std::endl;
    return 0;
}

// https://chat.openai.com/share/08683e74-ab2f-47bf-abdc-4c21b4cc2839