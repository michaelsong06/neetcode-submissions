class MyHashSet {
private:
    vector<vector<int>> buckets;

    int capacity;
    int occupied;

    double load_factor() {
        return ((double)occupied / capacity);
    }

    int hash(int x) {
        return x % capacity;
    }

    void expand() {
        capacity *= 2;
        vector<vector<int>> new_buckets(capacity);
        for (vector<int>& bucket : buckets) {
            for (int val : bucket) {
                new_buckets[hash(val)].push_back(val);
            }
        }
        buckets = new_buckets;
    }

public:
    MyHashSet() {
        capacity = 1;
        buckets.resize(capacity);
        occupied = 0;
    }
    
    void add(int key) {
        if (!contains(key)) buckets[hash(key)].push_back(key);
        occupied++;
        if (load_factor() >= 0.75) {
            expand();
        }
    }
    
    void remove(int key) {
        if (!contains(key)) return;
        auto it = find(buckets[hash(key)].begin(), buckets[hash(key)].end(), key);
        buckets[hash(key)].erase(it);
    }
    
    bool contains(int key) {
        return (find(buckets[hash(key)].begin(), buckets[hash(key)].end(), key) != buckets[hash(key)].end());
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */