class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size(), l = 0, r = n-1;
        int pivotIdx = n;

        while(pivotIdx != k) {
            pivotIdx = partition(points,l,r);
            if(pivotIdx > k) {
                r = pivotIdx - 1;
            } else {
                l = pivotIdx + 1;
            }
        }

        return vector<vector<int>> (points.begin(), points.begin() + k);
    }

private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int i = l, pivotIdx = r;
        int pivot = euclidean(points[pivotIdx]);

        for(int j=l; j<r; j++) {
            if(euclidean(points[j]) < pivot) {
                swap(points[i], points[j]);
                i++;
            }
        }
        swap(points[i],points[pivotIdx]);
        return i;
    }

    int euclidean(const vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }
};
