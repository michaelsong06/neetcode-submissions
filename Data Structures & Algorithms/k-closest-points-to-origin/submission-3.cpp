class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<float, vector<int>>, vector<pair<float, vector<int>>>, greater<pair<float, vector<int>>>> pq;

        for (vector<int>& point : points) {
            float dist = sqrt(point[0] * point[0] + point[1] * point[1]);
            pq.push({dist, point});

            cout << "[" << point[0] << "," << point[1] << "]: " << dist << endl;
        }

        vector<vector<int>> closest;
        for (int i = 0; i < k; ++i) {
            closest.push_back(pq.top().second);
            pq.pop();
        }

        return closest;
    }
};
