class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Minimum is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Minimum is in the left half including mid
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};
