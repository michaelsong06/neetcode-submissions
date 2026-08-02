class KthLargest {
private:
    priority_queue<int> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        for (int num : nums) {
            pq.push(num);
        }
        this->k = k;
    }
    
    int add(int val) {
        pq.push(val);
        vector<int> temp;
        for (int i = 0; i < k && !pq.empty(); ++i) {
            temp.push_back(pq.top());
            pq.pop();
        }
        int ret = temp.back();
        for (int num : temp) pq.push(num);
        return ret;
    }
};
