class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0]+b[1]*b[1];
        };

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            decltype(compare)> minHeap(compare);

        for(const auto& point : points) {
            minHeap.push(point);
        }

        vector<vector<int>> output;
        for(int i=0; i<k; i++) {
            output.push_back(minHeap.top());
            minHeap.pop();
        }

        return output;
    }
};
