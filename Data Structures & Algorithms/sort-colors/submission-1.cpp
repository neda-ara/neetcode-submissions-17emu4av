class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);

        for(int num : nums) { 	// O(n)
            count[num]++;
        }

        int idx = 0;
        for(int i=0; i<3; i++) {		// O(3), or constant
            while(count[i]-- > 0) {	// Total work across all i is O(n)
                nums[idx++] = i;
            }
        }
    }
};
