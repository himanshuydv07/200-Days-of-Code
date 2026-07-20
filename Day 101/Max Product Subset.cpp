

class Solution {
public:
    long long mod = 1e9 + 7;

    long long findMaxProduct(vector<int>& arr) {
        int n = arr.size();

        if (n == 1) return arr[0];

        long long product = 1;
        int negCount = 0, zeroCount = 0;
        int maxNegative = INT_MIN;

        for (int x : arr) {
            if (x == 0) {
                zeroCount++;
                continue;
            }

            if (x < 0) {
                negCount++;
                maxNegative = max(maxNegative, x);
            }

            product = (product * x) % mod;
        }

        // If all are zeros
        if (zeroCount == n) return 0;

        // If odd number of negatives, remove the negative
        // with least absolute value (largest negative)
        if (negCount % 2 == 1) {

            // only one negative and rest zeros
            if (negCount == 1 && zeroCount + negCount == n)
                return 0;

            product = product * modInverse(maxNegative) % mod;
        }

        return (product + mod) % mod;
    }

private:
    long long power(long long a, long long b) {
        long long res = 1;
        a = (a % mod + mod) % mod;

        while (b) {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    long long modInverse(long long x) {
        return power(x, mod - 2);
    }
};
