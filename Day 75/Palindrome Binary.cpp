class Solution {
  public:
    bool isBinaryPalindrome(int n) {
         string binary = "";

    // Convert to binary
    while (n > 0) {
        binary = char((n % 2) + '0') + binary;
        n /= 2;
    }

    // Check palindrome
    int left = 0, right = binary.size() - 1;
    while (left < right) {
        if (binary[left] != binary[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
    }
};
