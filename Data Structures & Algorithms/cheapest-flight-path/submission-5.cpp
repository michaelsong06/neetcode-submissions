class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // flights = {{0, 1, 100}, {1, 2, 100}, {0, 2, 500}};
        // src = 0;
        // dst = 2;
        // k = 1;

        vector<int> prices(n, 1001);
        prices[src] = 0;

        vector<int> temp_prices = prices;

        for (int i = 0; i < k + 1; ++i) {

            for (vector<int> flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];

                if (prices[from] + cost < temp_prices[to]) {
                    temp_prices[to] = prices[from] + cost;
                }

            }

            prices = temp_prices;
            temp_prices = prices;

            for (int i = 0; i < n; ++i) {
                cout << i << ": " << prices[i] << endl;
            }
            cout << endl;
        }

        if (prices[dst] == 1001) return -1;
        return prices[dst];

    }
};
