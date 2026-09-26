class Solution {
    unordered_map<int,vector<int>> courseToPrereq;
    unordered_set<int> visiting;

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++) {
            courseToPrereq[i] = {};
        }

        for(auto& prereq : prerequisites) {
            courseToPrereq[prereq[0]].push_back(prereq[1]);
        }

        for(int c=0; c<numCourses; c++) {
            if(!dfs(c)) {
                return false;
            }
        }

        return true;
    }

    bool dfs(int course) {
        if(visiting.count((course))) {
            return false;
        }
        if(courseToPrereq[course].empty()) {
            return true;
        }

        visiting.insert(course);

        for(int prereq : courseToPrereq[course]) {
            if(!dfs(prereq)) {
                return false;
            }
        }

        visiting.clear();
        courseToPrereq[course].clear();
        return true;
    }
};
