#include <iostream>
using namespace std;
int getBit(int num, int pos)
{
    return (num >> pos) & 1;
}
int setBit(int num, int pos)
{
    return num | (1 << pos);
}
int clearBit(int num, int pos)
{
    return num & ~(1 << pos);
}
int updateBit(int num, int pos, int bitValue)
{
    int mask = ~(1 << pos);
    return (num & mask) | (bitValue << pos);
}
int main()
{
    cout << updateBit(10, 1, 0);
    return 0;
}