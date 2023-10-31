# Check if the String Rotation is the Substring of the Actual String or Not.

To check if one string is a rotation of another using only one call to the `isSubstring` method, you can follow these steps:

1. Concatenate S1 with itself to create a new string, S1S2.
2. Check if S2 is a substring of S1S2.

If S2 is a rotation of S1, it should also be a substring of S1S1. This is because any rotation of S1 is essentially a substring of S1S1.

```cpp
#include <iostream>
#include <string>
using namespace std;
bool isRotationSubstring(const string &str1, const string &str2)
{
    return (str1.length() != str2.length()) ? false : ((str1 + str1).find(str2) != string::npos);
}
int main()
{
    cout << isRotationSubstring("waterbottle", "terbottlewa");
    return 0;
}
```

The line `((str1 + str1).find(str1) != string::npos)` is a common way to implement a simple string substring check. Here's what it does:
<br>

`(str1 + str2).find(str1)`: This part of the code searches for the `str2` within `str1 + str2`. The `find` function returns the position (index) in `str1 + str2` where the `str2` is found. If it doesn't find the `str2`, it returns a special constant value, `string::npos`, which is typically a large integer representing "not found".
