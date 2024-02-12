int main()
{
    std::vector<int> v{1, 2, 3, 4, 5};
    v.push_back(6);
    std::rotate(v.rbegin(), v.rbegin() + 1, v.rend());
}