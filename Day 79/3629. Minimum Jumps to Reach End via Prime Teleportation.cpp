class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int num : nums) {
            if (num > max_val) max_val = num;
        }

        // Step 1: Sieve of Eratosthenes to compute Smallest Prime Factor (SPF)
        vector<int> spf(max_val + 1);
        for (int i = 1; i <= max_val; ++i) spf[i] = i;
        for (int i = 2; i * i <= max_val; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        // Helper lambda to check if a number is prime in O(1)
        auto is_prime = [&](int x) {
            if (x <= 1) return false;
            return spf[x] == x;
        };

        // Step 2: Identify primes that actually appear as values in nums
        vector<bool> present_prime(max_val + 1, false);
        for (int x : nums) {
            if (is_prime(x)) {
                present_prime[x] = true;
            }
        }

        // Step 3: Map each available prime to the list of indices where nums[i] is a multiple
        vector<vector<int>> targets(max_val + 1);
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            
            // Fast factorization using SPF
            while (x > 1) {
                int p = spf[x];
                // Only build edges for primes we can actually teleport from
                if (present_prime[p]) {
                    targets[p].push_back(i);
                }
                // Remove all instances of the prime factor 'p'
                while (x % p == 0) x /= p;
            }
        }

        // Step 4: BFS to find the shortest path
        queue<int> q;
        vector<int> dist(n, -1);
        vector<bool> used_prime(max_val + 1, false); // Prevent duplicate teleport checks

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // If we've reached the last index, return the number of jumps
            if (curr == n - 1) {
                return dist[curr];
            }

            // Move 1: Adjacent Step Forward (i + 1)
            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }

            // Move 2: Adjacent Step Backward (i - 1)
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }

            // Move 3: Prime Teleportation
            if (is_prime(nums[curr]) && !used_prime[nums[curr]]) {
                int p = nums[curr];
                used_prime[p] = true; // Mark as used to prevent TLE
                
                for (int next_idx : targets[p]) {
                    if (dist[next_idx] == -1) {
                        dist[next_idx] = dist[curr] + 1;
                        q.push(next_idx);
                    }
                }
            }
        }

        return -1;
    }
};
