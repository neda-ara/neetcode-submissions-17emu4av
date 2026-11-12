class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        vector<vector<int>> segments;
        vector<int> curr;

        int res = nums[0];
        for (int& num : nums) {
            res = max(res, num);
            if (num == 0) {
                if (!curr.empty()) {
                    segments.push_back(curr);
                }
                curr.clear();
            } else {
                curr.push_back(num);
            }
        }
        if (!curr.empty()) {
            segments.push_back(curr);
        }

        for (auto& seg : segments) {
            int negs = 0;
            for (int num : seg) {
                if (num < 0) {
                    negs++;
                }
            }

            int prod = 1, l = 0;
            int allowed_negs = negs % 2 == 0 ? negs : negs - 1;
            negs = 0;

            for (int r = 0; r < seg.size(); r++) {
                // 1. Expand window to the right.
                prod *= seg[r];

                // 2. If we added a negative, update negative count.
                if (seg[r] < 0) {
                    negs++;

                    // 3. If window has too many -ves, remove elements from the left.
                    while (negs > allowed_negs) {
                        // Remove leftmost element's contribution.
                        prod /= seg[l];

                        // If removed element was -ve, update negative count.
                        if (seg[l] < 0) {
                            negs--;
                        }
                        // Move left boundary forward.
                        l++;
                    }
                }
                // 4. Only consider a non-empty window.
                if (l <= r) {
                    res = max(res, prod);
                }
            }
        }
        return res;
    }
};
