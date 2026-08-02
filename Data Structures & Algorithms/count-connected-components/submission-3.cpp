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
    int countComponents(int n, vector<vector<int>>& edges) {
        
        parent.resize(n);
        for (int i = 0; i < n; ++i) parent[i] = i;
        size.resize(n);
        for (int i = 0; i < n; ++i) size[i] = 1;

        for (vector<int>& edge : edges) {
            unite(edge[0], edge[1]);
        }

        set<int> components;
        for (int i = 0; i < n; ++i) {
            components.insert(find(i));
        }

        return components.size();
    }
};
