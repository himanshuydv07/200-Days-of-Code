class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
          priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<int> result;

    for (int x : arr) {
        minHeap.push(x);

        // Keep only k largest elements
        if (minHeap.size() > k) {
            minHeap.pop();
        }

        // If less than k elements, answer is -1
        if (minHeap.size() < k) {
            result.push_back(-1);
        } else {
            result.push_back(minHeap.top());
        }
    }

    return result;
    }
};
