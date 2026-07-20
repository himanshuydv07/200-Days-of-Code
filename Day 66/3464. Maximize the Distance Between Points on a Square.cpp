class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> positions;
        positions.reserve(points.size());

        for (const vector<int>& point : points) {
            int x = point[0];
            int y = point[1];

            if (x == 0) {
                positions.push_back(y);
            } else if (y == side) {
                positions.push_back(1LL * side + x);
            } else if (x == side) {
                positions.push_back(3LL * side - y);
            } else {
                positions.push_back(4LL * side - x);
            }
        }

        sort(positions.begin(), positions.end());

        int answer = 0;
        long long left = 1;
        long long right = side;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canPick(positions, side, k, mid)) {
                answer = static_cast<int>(mid);
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return answer;
    }

private:
    bool canPick(const vector<long long>& positions, int side, int k, long long limit) {
        long long perimeter = 4LL * side;

        for (long long start : positions) {
            long long lastAllowed = start + perimeter - limit;
            long long current = start;
            bool possible = true;

            for (int picked = 1; picked < k; picked++) {
                auto it = lower_bound(positions.begin(), positions.end(), current + limit);

                if (it == positions.end() || *it > lastAllowed) {
                    possible = false;
                    break;
                }

                current = *it;
            }

            if (possible) {
                return true;
            }
        }

        return false;
    }
};
