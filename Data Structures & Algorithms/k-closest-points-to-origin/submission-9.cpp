class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         int n = points.size();
         int l = 0, r = n - 1, pivot = n-1;

        while(pivot != k-1) {
            pivot = partition(points, l, r);
            if(pivot > k-1) {
                r = pivot - 1;
            } else {
                l = pivot + 1;
            }
        }

        return vector<vector<int>> (points.begin(),points.begin()+k);
    }

private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivotIdx = r, i = l;
        int pivotDist = euclidean(points[pivotIdx]);

        for(int j=l; j<r; j++) {
            if(euclidean(points[j]) < pivotDist) {
                swap(points[i],points[j]);
                i++;
            }
        }
        swap(points[i],points[r]);
        return i;
    }

    int euclidean(vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }
};
