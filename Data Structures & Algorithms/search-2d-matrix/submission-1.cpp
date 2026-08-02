class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int outerL = 0;
        int outerR = matrix.size() - 1;

        int rowIndex = -1;

        while (outerL <= outerR && rowIndex == -1) {
            int outerMid = (outerL + outerR) / 2;
            cout << outerMid << "\n";
            vector<int> row = matrix[outerMid];
            for (int n : row) cout << n << " ";
            cout << "\n";
            if (row[0] <= target && row.back() >= target) {
                rowIndex = outerMid;
            } else if (row[0] > target && row.back() > target) {
                outerR = outerMid - 1;
            } else if (row[0] < target && row.back() < target) {
                outerL = outerMid + 1;
            }
        }

        cout << rowIndex << "\n";
        if (rowIndex == -1) return false;

        int innerL = 0;
        int innerR = matrix[rowIndex].size() - 1;
        vector<int> row = matrix[rowIndex];

        

        while (innerL <= innerR) {
            int innerMid = (innerL + innerR) / 2;
            if (row[innerMid] > target) {
                innerR = innerMid - 1;
            } else if (row[innerMid] < target) {
                innerL = innerMid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
