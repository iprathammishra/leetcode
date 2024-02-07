unordered_map<int, int> fmap;
vector<char> uniqueCharacters;
sort(uniqueCharacters.begin(), uniqueCharacters.end(), [&](int a, int b)
     { return fmap[a] > fmap[b]; });