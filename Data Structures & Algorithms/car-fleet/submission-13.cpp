class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();

        // Sort the positions into descending order
        unordered_map<int, int> posSpeed;
        for (int i = 0; i < n; ++i) posSpeed[position[i]] = speed[i];
        sort(position.begin(), position.end(), greater<int>());
        for (int i = 0; i < n; ++i) speed[i] = posSpeed[position[i]];

        stack<float> times;
        times.push((target - position[0]) / speed[0]);

        cout << times.top() << "\n";
        for (int i = 1; i < n; ++i) {
            float time = (target - position[i]) / float(speed[i]);
            cout << time << "\n";
            if (times.top() < time) {
                times.push(time);
            }
        }

        return times.size();

    }
};
