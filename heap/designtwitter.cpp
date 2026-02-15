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
//stores all tweets of each user
// key   = userId
// value = list of (timestamp, tweetId)
// vector used because user can post multiple tweets
// timestamp used to identify latest tweet
// unordered_map used for O(1) access

//unordered_map<
//     int,                // userId
//     vector<pair<int,int>> // list of (timestamp, tweetId)
// >



unordered_map<int,unordered_set<int>>followees;
//stores list of users that a person follows
//key   = followerId
//value = set of followeeIds
//unordered_set used to avoid duplicates
//unordered_map used for O(1) access

//followerId → set of users he follows




public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++timer,tweetId});

        //User ke tweet ko timestamp ke sath store kar rahe hain taaki latest tweets identify kar sakein.
    }
    
     //Ye function latest 10 tweets return karta hai user + uske followees ke
    vector<int> getNewsFeed(int userId) {
        vector<int>res;//final answer store karega (tweetIds)
        followees[userId].insert(userId);//taaki uske khud ke tweets bhi news feed me aaye
        priority_queue<tuple<int,int,int>>pq;//(timestamp, userId, tweetIndex)
// Heap top = latest tweet.
// Revision note:
// max heap used to get latest tweet
        for(int f:followees[userId])//Loop runs for:
                                    //user + all followees
        {
            if(!tweets[f].empty()){//check agar tweets exist karte hain
                int idx=tweets[f].size()-1;//latest tweet ka index
//because latest tweet always last me hota hai.
                pq.push({tweets[f][idx].first,f,idx});//push:
                                                      //(timestamp, userId, index)

            }
        }
        //Example heap:
// (10,1,2)
// (8,2,1)
// (6,3,0)

 
          //run until:heap empty OR 10 tweets mil jaye
        while(!pq.empty() &&res.size()<10)//heap se latest tweets nikalna
        {
            auto[time,uid,idx]=pq.top();
            pq.pop();
            //(10,1,2)

            res.push_back(tweets[uid][idx].second);//result me tweetId add kiya
            //second = tweetId

            if(idx>0)
            {
                //latest tweet index = 2
                //next tweet index = 1
                pq.push({tweets[uid][idx-1].first,uid,idx-1});
            }

        }
        return res;//final answer return
// contains:
// latest 10 tweetIds
        

    }
    
    void follow(int followerId, int followeeId) {
        //Follower ki follow list me followee ko add kar rahe hain.
        if(followerId!=followeeId)
        {
            followees[followerId].insert(followeeId);
        }
        
    }
    
    void unfollow(int followerId, int followeeId) {
        //Follower ki follow list se followee ko remove kar rahe hain.
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