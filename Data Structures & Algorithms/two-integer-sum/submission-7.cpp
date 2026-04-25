class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> track;
       int n = nums.size();

       for(int i=0; i<n; i++) {
        int comp = target - nums[i];
        if(track.find(comp) != track.end()) {
            return {track[comp],i};
        }
        track[nums[i]] = i;
       }

       return {}; 
    }
};
