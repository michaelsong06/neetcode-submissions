class Solution {
private:

    vector<int> parent;
    vector<int> size;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void onion(int x, int y) {
        x = find(x);
        y = find(y);
        if (size[x] < size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
        for (int i = 1; i <= n; ++i) size[i] = 1;

        for (vector<int>& edge : edges) {
            int n1 = edge[0], n2 = edge[1];
            if (find(n1) == find(n2)) {
                return edge;
            } else {
                onion(n1, n2);
            }
        }

        return {};
    }
};
