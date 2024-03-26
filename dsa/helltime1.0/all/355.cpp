class Twitter
{
public:
    unordered_map<int, unordered_set<int>> users;
    unordered_map<int, priority_queue<pair<int, int>>> user_posts;
    int time = 0;

    Twitter() {}

    void postTweet(int userid, int tweetid)
    {
        user_posts[userid].push({time++, tweetid});
    }

    vector<int> getNewsFeed(int userid)
    {
        vector<int> ans;
        priority_queue<pair<int, pair<int, int>>> result;
        vector<pair<int, pair<int, int>>> reset;

        if (user_posts.find(userid) != user_posts.end() && !user_posts[userid].empty())
            result.push({user_posts[userid].top().first, {userid, user_posts[userid].top().second}});

        for (auto i : users[userid])
        {
            if (user_posts.find(i) != user_posts.end() && !user_posts[i].empty())
                result.push({user_posts[i].top().first, {i, user_posts[i].top().second}});
        }

        while (ans.size() < 10 && !result.empty())
        {
            pair<int, pair<int, int>> temp = result.top();
            int uid = temp.second.first, tid = temp.second.second, ts = temp.first;
            ans.push_back(tid);
            result.pop();

            if (user_posts.find(uid) != user_posts.end() && !user_posts[uid].empty())
            {
                user_posts[uid].pop();
                reset.push_back(temp);
                if (!user_posts[uid].empty())
                    result.push({user_posts[uid].top().first, {uid, user_posts[uid].top().second}});
            }
        }

        while (!reset.empty())
        {
            pair<int, pair<int, int>> temp = reset.back();
            user_posts[temp.second.first].push({temp.first, temp.second.second});
            reset.pop_back();
        }

        return ans;
    }

    void follow(int followerid, int followeeid)
    {
        users[followerid].insert(followeeid);
    }

    void unfollow(int followerid, int followeeid)
    {
        users[followerid].erase(followeeid);
    }
};