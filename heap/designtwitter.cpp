//question kya hai--
//Tumhe ek Twitter jaisa system design karna hai jisme 4 functions honge
// 1. postTweet(userId, tweetId)
// 2. getNewsFeed(userId)
// 3. follow(followerId, followeeId)
// 4. unfollow(followerId, followeeId)
//Real life example se samjho
//User 1
//User 2
//User 3

// 1️⃣ postTweet(userId, tweetId)
// User apna tweet post karta hai.
// Example
// postTweet(1,101)
// postTweet(2,201)


// Matlab:

// User 1 ne tweet 101 kiya
// User 2 ne tweet 201 kiya


// 2️⃣ follow(followerId, followeeId)
// User kisi aur ko follow karta hai.
// Example:
// follow(1,2)
// Matlab:
// User 1 ab User 2 ko follow karta hai


// 3️⃣ getNewsFeed(userId)
// Ye sabse important function hai.
// Isme return karna hai:
// latest 10 tweets
// From:
// • khud ke tweets
// • jinhe wo follow karta hai
// Example:
// User 1 tweets → 101
// User 2 tweets → 201
// User 1 follows User 2
// Output:
// getNewsFeed(1) → [201,101]
// Latest tweet pehle.


// 4️⃣ unfollow(followerId, followeeId)
// Example:
// unfollow(1,2)
// Matlab:
// User 1 ab User 2 ko follow nahi karta
// Now:
// getNewsFeed(1) → [101]


// Important rules
// Rule 1:
// Return only:
// latest 10 tweets
// Even if 100 tweets exist.
// Rule 2:
// Tweets sorted by:
// latest first
// Not by tweetId, but by time.

class Twitter {

int timer=0;//assign timestamp to each tweet
// so we can find latest tweets using heap

unordered_map<int,vector<pair<int,int>>>tweets;
unordered_map<int,unordered_set<int>>followees;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>res;
        followees[userId].insert(userId);
        priority_queue<tuple<int,int,int>>pq;

        for(int f:followees[userId])
        {
            if(!tweets[f].empty())
            {
                int idx=tweets[f].size()-1;
                pq.push({tweets[f][idx].first,f,idx});
            }
        }
        while(!pq.empty() && res.size()<10)
        {
            auto[time,uid,idx]=pq.top();
            pq.pop();
            res.push_back(tweets[uid][idx].second);

            if(idx>0)
            {
                pq.push({tweets[uid][idx-1].first,uid,idx-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
        {
            followees[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */