// Tumhe ek integer array nums diya gaya hai aur ek number k diya hai. Tumhe array ka k-th largest element nikalna hai.
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //We use a heap because it lets us track only the k largest elements without sorting the entire array, improving efficiency.
//Kth largest → min heap of size 
//Kth smallest → max heap of size k

//Sabse pehle ye yaad rakho
//Heap sorted array nahi hota

//Min Heap guarantee:
//Sirf ek cheez pakki
//Top element = sabse chhota

//Max Heap guarantee:
//Sirf ek cheez pakki
//Top element = sabse chhota

//nums = [3,2,1,5,6,4]
//k = 2
//Heap = min-heap (size ≤ 2)


//greater<int> lagaya → min heap ban gaya

// priority_queue ko andar se data store karne ke liye ek container chahiye hota hai
// Aur C++ by default vector use karta hai.
        priority_queue<int,vector<int>,greater<int>>pq;

        //are bhai ye min element hmedha pop kr rhe hai to akhir me 2 max elemnt bchenge aur kuki jo chota hoga vhe upr ayega

        for(int num:nums){
            pq.push(num);
            if(pq.size()>k)pq.pop();
        }

        //top pe apne aap pe aa jayega
        return pq.top();
    }
};