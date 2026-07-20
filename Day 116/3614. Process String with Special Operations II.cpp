class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
    // store the length of the result string after processing each character s[i]
    vector<long long> lengths(n, 0);
    long long current_len = 0;

    // Step 1: Forward pass to compute lengths at each step
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            current_len++;
        } else if (s[i] == '*') {
            if (current_len > 0) current_len--;
        } else if (s[i] == '#') {
            current_len *= 2;
        } else if (s[i] == '%') {
            // Reverse doesn't change the length
        }
        lengths[i] = current_len;
    }

    // If k is out of bounds of the final string length, return '.'
    if (k < 0 || k >= current_len) {
        return '.';
    }

    // Step 2: Backward pass to track the index k
    for (int i = n - 1; i >= 0; --i) {
        // Find the length *before* the current operation s[i]
        long long prev_len = (i == 0) ? 0 : lengths[i - 1];

        if (s[i] >= 'a' && s[i] <= 'z') {
            // If the current length equals k + 1, it means s[i] is our target character
            if (lengths[i] == k + 1) {
                return s[i];
            }
        } else if (s[i] == '*') {
            // Moving backward past a delete means the string was longer before this step
            // k stays the same because the deleted character was at the very end
        } else if (s[i] == '#') {
            // If k falls into the duplicated second half, map it back to the first half
            if (k >= prev_len) {
                k -= prev_len;
            }
        } else if (s[i] == '%') {
            // Reverse maps the index to its mirror image
            if (lengths[i] > 0) {
                k = lengths[i] - 1 - k;
            }
        }
    }

    return '.';
    }
};
