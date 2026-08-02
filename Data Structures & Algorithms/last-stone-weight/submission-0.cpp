class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for (int stone : stones) pq.push(stone);

        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();

            if (x == y) continue;

            if (y < x) swap(y, x);
            y -= x;
            pq.push(y);
        }

        return (pq.size() == 1) ? pq.top() : 0;
    }
};
