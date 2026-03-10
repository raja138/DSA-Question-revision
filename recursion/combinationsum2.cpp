// तो "Combination Sum II" में हमें एक ऐसा कैंडिडेट 
//नंबरों का सेट दिया जाता है, जिसमें कुछ नंबर दोहराए जा सकते हैं।
//  अब हर नंबर सिर्फ एक बार इस्तेमाल कर सकते हैं। हमें ऐसे सभी यूनिक
//   कॉम्बिनेशन ढूंढने हैं जिनका योग हमारे टार्गेट के बराबर हो। इसके लिए हम 
//   पहले लिस्ट को सॉर्ट करते हैं, ताकि डुप्लिकेट को आसानी से स्किप कर सकें। 
//   फिर हम बैकट्रैकिंग करते हैं: हर स्टेप पर नंबर चुनते हैं, टार्गेट घटाते हैं, और 
//   आगे बढ़ते हैं। डुप्लिकेट कॉम्बिनेशन ना आए, इसलिए हम वही नंबर एक ही लेवल 
//   पर दोबारा नहीं चुनते। इस तरह, हमें यूनिक कॉम्बिनेशन मिलते हैं जो टार्गेट को पूरा करते हैं।
class Solution {
public:

    void solve(int index, vector<int>& candidates, int target,
               vector<int>& temp, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if(candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, temp, ans);

        return ans;
    }
};