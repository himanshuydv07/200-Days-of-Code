class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum is in right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum is in left half including mid
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            // Duplicates: reduce search space
            else {
                high--;
            }
        }

        return nums[low];
    }
};
