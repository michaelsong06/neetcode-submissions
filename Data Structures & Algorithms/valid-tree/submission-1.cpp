class Solution {
private:

    vector<int> parent;
    vector<int> size;
    
    int find(int a) {
        if (parent[a] != a) parent[a] = find(parent[a]);
        return parent[a];
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }

        for (vector<int>& edge : edges) {
            if (find(edge[0]) == find(edge[1])) return false;
            unite(edge[0], edge[1]);
        }

        set<int> reps;
        for (int i = 0; i < n; ++i) {
            reps.insert(find(i));
        }

        return (reps.size() == 1);
    }
};
