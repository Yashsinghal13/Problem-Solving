int countElements(vector<int>& arr, int mide) {
    int low = 0;
    int high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= mide) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

// Function to find the median of a matrix
int Solution::findMedian(vector<vector<int>>& matrix) {
    // Define the search space 
    int low = 1;
    int high = INT_MAX;
    int rows = matrix.size();
    int cols = matrix[0].size();
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < rows; i++) {
            count += countElements(matrix[i], mid);
        }
        // Check the median condition 
        if (count <= (rows * cols) / 2) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
