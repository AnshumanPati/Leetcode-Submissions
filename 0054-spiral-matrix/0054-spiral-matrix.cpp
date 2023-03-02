class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) {
            return result;
        }

        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;

        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            // Traverse right
            for (int j = colBegin; j <= colEnd; ++j) {
                result.push_back(matrix[rowBegin][j]);
            }
            ++rowBegin;

            // Traverse down
            for (int i = rowBegin; i <= rowEnd; ++i) {
                result.push_back(matrix[i][colEnd]);
            }
            --colEnd;

            if (rowBegin <= rowEnd) {
                // Traverse left
                for (int j = colEnd; j >= colBegin; --j) {
                    result.push_back(matrix[rowEnd][j]);
                }
                --rowEnd;
            }

            if (colBegin <= colEnd) {
                // Traverse up
                for (int i = rowEnd; i >= rowBegin; --i) {
                    result.push_back(matrix[i][colBegin]);
                }
                ++colBegin;
            }
        }

        return result;
    }
};