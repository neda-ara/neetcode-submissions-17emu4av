class Solution {
    unordered_map<int,vector<int>> courseToPreReq;
    unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++) {
            courseToPreReq[i] = {};
        }
        for(const auto& prereq : prerequisites) {
            courseToPreReq[prereq[0]].push_back(prereq[1]);
        }

        for(int c=0; c<numCourses; c++) {
            if(!dfs(c)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int course) {
        if(visiting.count(course)) {
            return false;
        }
        if(courseToPreReq[course].empty()) {
            return true;
        }
        visiting.insert(course);
        for(int prereq : courseToPreReq[course]) {
            if(!dfs(prereq)) {
                return false;
            }
        }
        visiting.erase(course);
        courseToPreReq[course].clear();
        return true;
    }
};
