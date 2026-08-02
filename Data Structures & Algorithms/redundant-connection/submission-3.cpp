class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        vector<int> eq_classes(n + 1);
        for (int i = 1; i <= n; ++i) {
            eq_classes[i] = i;
        }

        vector<int> candidates;

        for (vector<int>& edge : edges) {
            if (eq_classes[edge[0]] == eq_classes[edge[1]]) {
                return edge;
            } else {
                int old_class = eq_classes[edge[0]];
                for (int i = 1; i <= n; ++i) {
                    if (eq_classes[i] == old_class) {
                        eq_classes[i] = eq_classes[edge[1]];
                    }
                }
            }
        }

        return {};
    }
};
