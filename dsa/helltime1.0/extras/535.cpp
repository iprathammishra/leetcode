class Solution
{
private:
    unordered_map<string, string> urlMap;
    int counter = 0;
    string domain = "http://tinyurl.com/";

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string key = to_string(++counter);
        urlMap[key] = longUrl;
        return domain + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int lastPosition = shortUrl.rfind('/') + 1;
        return urlMap[shortUrl.substr(lastPosition, shortUrl.size() - lastPosition)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));