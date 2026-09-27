class Solution {
    unordered_map<int,vector<int>> courseToPrereq;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> output;
        unordered_set<int> visited;
        unordered_set<int> cycle;
        

        for(auto& prereq : prerequisites) {
            courseToPrereq[prereq[0]].push_back(prereq[1]);
        }

        for(int course=0; course<numCourses; course++) {
            if(!dfs(course,visited,cycle,output)) {
                return {};
            }
        }

        return output;
    }

    bool dfs(int course, unordered_set<int>& visited, unordered_set<int>& cycle, vector<int>& output) {
        if(cycle.count(course)) {
            return false;
        }
        if(visited.count(course)) {
            return true;
        }
        cycle.insert(course);

        if(courseToPrereq.count(course)) {
            for(int prereq : courseToPrereq[course]) {
                if(!dfs(prereq,visited,cycle,output)) {
                    return false;
                }
            }
        }

        cycle.erase(course);
        visited.insert(course);
        output.push_back(course);
        return true;
    }
};
