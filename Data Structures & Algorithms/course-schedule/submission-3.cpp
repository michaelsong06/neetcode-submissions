class Solution {
private:
    vector<vector<int>> graph;
    vector<int> states; // 0 - unvisited, 1 - visiting, 2 - visited
    bool cycle = false;

    void dfs(int current) {

        if (cycle) return;
        
        if (states[current] == 1) {
            cycle = true;
            return;
        }

        if (states[current] == 2) return;

        states[current] = 1;

        for (int course : graph[current]) {
            dfs(course);
        }

        states[current] = 2;
        
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        graph.resize(numCourses);
        states.resize(numCourses);

        for (vector<int>& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }
        for (int i = 0; i < numCourses; ++i) states[i] = 0;

        for (int i = 0; i < numCourses; ++i) {
            if (states[i] == 0) dfs(i);
        }

        return !cycle;
    }
};
