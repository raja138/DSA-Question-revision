class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int runningSum = 0;
        unordered_map<int, int> sumFrequency;
        sumFrequency[0] = 1; // शुरूआत में 0 सम एक बार है

        //bhai jo running sum aaye map me uski freq store kr lo
        //for example--
        //रनिंग सम: 1
        //मैप: {0: 1}
        //रनिंग सम: 1
        //मैप: {0: 1, 1: 1}
        //रनिंग सम: 3
        //{0: 1, 1: 1, 3: 1}
        //रनिंग सम: 6
        //मैप: {0: 1, 1: 1, 3: 1, 6: 1}

        for (int i = 0; i < nums.size(); i++) {
            runningSum += nums[i];
            //Ye recursion ya nested loop ko simulate kar raha hai
            //but smartly, prefix history yaad rakh ke.
            if (sumFrequency.count(runningSum - k)) {
                count += sumFrequency[runningSum - k];
            }

            sumFrequency[runningSum]++; // मौजूदा रनिंग सम को मैप में जोड़ना
        }

        return count;
    }
};