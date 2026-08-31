class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int pivot = n, l = 0, r = n-1;

        while(pivot != k) {
            pivot = partition(points, l ,r);
            if(pivot < k) {
                l = pivot + 1;
            } else {
                r = pivot - 1;
            }
        }
        return vector<vector<int>> (points.begin(),points.begin()+k);
    }

private:
    int partition(vector<vector<int>>& points, int l, int r) {
        int pivotIdx = r;
        int pivotDist = distance(points[pivotIdx]);
        int i = l;

        for(int j=l; j<r; j++) {
            if(distance(points[j]) <= pivotDist) {
                swap(points[i],points[j]);
                i++;
            }
        }
        swap(points[i],points[r]);
        return i;
    }

    int distance(const vector<int>& point) {
        return point[0]*point[0] + point[1]*point[1];
    }
};
