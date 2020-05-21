class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v;
        unordered_map<int,int> u;
        int diff;
        for(int i = 0;i < nums.size();i++){
            diff = target - nums[i];
            if(u.find(diff)!=u.end()){//差と等しい値を持つものが見つかった
                v.push_back(u[diff]);
                v.push_back(i);
                break;
            }      
            else{
                u[nums[i]] = i;//値から添え字を呼ぶ
            }
     }
        return v;
    }
};