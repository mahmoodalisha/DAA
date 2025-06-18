//Search in a sorted 2D matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n -1;

        while(left<=right){
            int mid = (left + right) / 2;
            int mid_value = matrix[mid / n][mid % n];  // Convert the 1D index back to 2D

            if(mid_value == target){
                return true;
            }
            else if(mid_value<target){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return false;
    }
};