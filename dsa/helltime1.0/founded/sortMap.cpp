unordered_map<int, int> map;
for (const int &value : arr)
{
    map[value]++;
}
vector<pair<int, int>> freq(map.begin(), map.end());
sort(freq.begin(), freq.end(), [&](pair<int, int> a, pair<int, int> b)
     { return a.second < b.second; });