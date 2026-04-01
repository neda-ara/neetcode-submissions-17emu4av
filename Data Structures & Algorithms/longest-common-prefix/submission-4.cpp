class Solution {
public:
    string commonPrefix(const string& left, const string& right) {
        int minLength = min(left.size(), right.size());

        for(int i=0; i<minLength; i++) {
            if(left[i] != right[i]) {
                return left.substr(0,i);
            }
        }

        return left.substr(0,minLength);
    }
 
    string getLcp(vector<string>& strs, int left, int right) {
        if(left==right) {
            return strs[left];
        }

        int mid = (left+right)/2;

        string lcpLeft = getLcp(strs, left, mid);
        string lcpRight = getLcp(strs, mid+1, right);

        return commonPrefix(lcpLeft, lcpRight);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) {
            return "";
        }

        return getLcp(strs, 0, strs.size() - 1);
    }
};