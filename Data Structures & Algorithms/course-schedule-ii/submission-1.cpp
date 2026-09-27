class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> output;
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for(auto& prereq : prerequisites) {
            indegree[prereq[0]]++;
            adj[prereq[1]].push_back(prereq[0]);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int course = q.front();
            q.pop();
            output.push_back(course);

            for(int dependent : adj[course]) {
                indegree[dependent]--;
                if(indegree[dependent] == 0) {
                    q.push(dependent);
                }
            }
        }

        if(output.size() == numCourses) {
            return output;
        }
        return {};
    }
};
