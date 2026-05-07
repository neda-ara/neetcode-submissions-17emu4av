class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int idx = 0;

        int res = n;
        for(int sandwich : sandwiches) {
            int cnt = 0;

            while(cnt < n && sandwich != students[idx]) {
                idx++;
                idx %= n;
                cnt++;
            }
            if(students[idx] == sandwich) {
                students[idx] = -1;
                res--;
            } else {
                break;
            }
        }
        return res;
    }
};