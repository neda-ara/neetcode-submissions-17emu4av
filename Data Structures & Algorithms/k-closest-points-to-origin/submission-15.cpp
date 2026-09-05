class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
        };

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            decltype(compare)> maxHeap(compare);

        for(const auto& point : points) { // O(n.logk)
            maxHeap.push(point);
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> output;
        for(int i=0; i<k; i++) { // (k.logn)
            output.push_back(maxHeap.top());
            maxHeap.pop();
        }

        return output;
    }
};
