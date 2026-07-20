class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long minLandEnd = LLONG_MAX;
        for (int i = 0; i < n; i++) {
            minLandEnd = min(minLandEnd,
                             (long long)landStartTime[i] + landDuration[i]);
        }

        long long ans = LLONG_MAX;

        // Land ride -> Water ride
        for (int j = 0; j < m; j++) {
            long long startWater =
                (minLandEnd <= waterStartTime[j])
                    ? waterStartTime[j]
                    : minLandEnd;

            ans = min(ans, startWater + waterDuration[j]);
        }

        long long minWaterEnd = LLONG_MAX;
        for (int j = 0; j < m; j++) {
            minWaterEnd = min(minWaterEnd,
                              (long long)waterStartTime[j] + waterDuration[j]);
        }

        // Water ride -> Land ride
        for (int i = 0; i < n; i++) {
            long long startLand =
                (minWaterEnd <= landStartTime[i])
                    ? landStartTime[i]
                    : minWaterEnd;

            ans = min(ans, startLand + landDuration[i]);
        }

        return (int)ans;
    }
};
