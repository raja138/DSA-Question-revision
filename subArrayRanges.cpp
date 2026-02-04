class Solution {
public:
//nums = [1, 2, 3]
// Subarrays:
// [1]-range-0
// [1,2]-range-1
// [1,2,3]--range-2
// [2]--range-0
// [2,3]--range--1
// [3]--range-0(3-3)
//range ka formula

//few things-element itself is not contributing to the answer

//logic vhi hai ki subarray max k liye us element ko dekho kitne me bnega max
// min me dekho kitne me bnenge 
//max-min kr do to range mil jayegi

//max ka logic jo yaad rkhna hai
//while me jb tk stack empty na ho and and dusri condition me or condition hai 
//ek to ki i==n ho ya dusri nums[st.top()]<nums[i]
//ab mid ho jayega stack ka top 
//stack se kr do pop
//left nikalo vo depend krega agar stack empty hai to mid+1 nhi to mid-st.top
//right--i-mid;
//else condition me last me stack me push kr do i ko
// ab min nikalne k liye bs nums[st.top()] > nums[i]) ye condition changed
// last me max se min minus kr do return kr do 
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumMax = 0, sumMin = 0;
        //int ka long long 1LL
        {
            //ise rat lo aise hi 
            //[1,2,3]
            //stack-[]
            stack<int> st;
            for (int i = 0; i <= n; i++) {
                //1-->i=0
                //2--->i=1
                //2--->stack-top->>[0]
                //2-->n-->3
                //2-->nums[st.top()]---->st.top()-->1,nums[1]<nums[1]--nhi aisa nhi hai
                //2-->>stack me aa gya 1 to stack ho gya--[0,1]<<top stack yha se dekho

                //3-->i=2
                //3--->[0,1]<---stack-top
                //3--->n=3  i==n -false hai
                //3-->nums[st.top()]---->st.top()-->1,nums[1]<nums[2]--haa hai aisa
                while (!st.empty() && (i == n || nums[st.top()] < nums[i])) {

                    int mid = st.top();
                    //3-->>mid=1-->>st.top()-->1
                    st.pop();
                    //3->>stack se pop--stack--[0]
                    //3--->>st.empty()--false
                    //3--->mid-st.top()--->>>left=1-0=1//left bhi 1
                    int left = st.empty() ? mid + 1 : mid - st.top();
                    //3-->right==>>i=2--mid=1//right=2-1=1//right=1
                    int right = i - mid;
                    //3-->>sumMax=0 
                    //3-->mid=1
                    //3-->nums[mid]--nums[1]--left->>1--right-->1
                    //3---->>sumMax=1*1*1=1
                    sumMax += 1LL * nums[mid] * left * right;
                }
                //1->stack me 0 push ho gya hai--stack[0]
                // 2->>stack me 1 push hua
                st.push(i);
            }
        }

        // ---------- SUM OF SUBARRAY MIN ----------
        {
            stack<int> st;
            for (int i = 0; i <= n; i++) {
                //upr waale se bs ye hi change hai
                //nums[st.top()] > nums[i])
                while (!st.empty() && (i == n || nums[st.top()] > nums[i])) {
                    int mid = st.top();
                    st.pop();
                    int left = st.empty() ? mid + 1 : mid - st.top();
                    int right = i - mid;
                    sumMin += 1LL * nums[mid] * left * right;
                }
                st.push(i);
            }
        }

        return sumMax - sumMin;
    }
};
