class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int candidate = 1; // lowest possible +ve no that could be missing

        while(true) {
            //we'll run the infinite loop till the missing candidate is found
            bool isCurrCandidateMissing = true; // based on current assumption

            for(int num : nums) {
                if(num == candidate) {
                    isCurrCandidateMissing = false;
                    break; // exit the loop as soon as assumption proved wrong
                }
            }
            // if our assumption was right and chosen one isn't present in array, return it
            if(isCurrCandidateMissing) return candidate;
            // if our assumption was wrong, scan the entire array again to check for new candidate
            candidate++;
        }
    }
};