class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto& prereq : prerequisites) {
            indegree[prereq[0]]++;
            adj[prereq[1]].push_back(prereq[0]);
        }

        queue<int> availableCoursesQ;
        int finishedCourses = 0;

        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                availableCoursesQ.push(i);
            }
        } 

        while(!availableCoursesQ.empty()) {
            finishedCourses++;
            int course = availableCoursesQ.front();
            availableCoursesQ.pop();

            for(int dependent : adj[course]) {
                indegree[dependent]--;
                if(indegree[dependent] == 0) {
                    availableCoursesQ.push(dependent);
                }
            }
        }  

        return finishedCourses == numCourses;
    }
};
