class Solution {
public:
    struct compare {
        inline bool operator() (const pair<int, int> a, const pair<int, int> b) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
    };

    int findValidSplit(vector<int>& nums) {
        if (nums[0] == 1) {
            if (nums.size() == 1) {
                return -1;
            }
            else {
                return 0;
            }
        }
        unordered_map<int, int> left, right;
        vector<int> primes;
        primes.push_back(2);
        bool flag;
        for (int i = 3; i <= 1001; i += 2) {
            flag = true;
            for (int j = 0; j < primes.size(); j++) {
                if ((i % primes[j]) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                primes.push_back(i);
            }
        }

        vector<pair<int, int>> intervals;
        for (int p = 0; p < primes.size(); p++) {
            pair<int, int> interval = { INT_MAX, INT_MIN };
            for (int n = 0; n < nums.size(); n++) {
                while ((nums[n] % primes[p]) == 0) {
                    nums[n] /= primes[p];
                    interval.first = (n < interval.first) ? n : interval.first;
                    interval.second = (interval.second < n) ? n : interval.second;
                }
            }
            if (interval.first != interval.second) {
                intervals.push_back(interval);
            }
        }
        int temp;
        for (int p = 0; p < nums.size(); p++) {
            if (nums[p] == 1) {
                continue;
            }
            temp = nums[p];
            pair<int, int> interval = { INT_MAX, INT_MIN };
            for (int n = p; n < nums.size(); n++) {
                while ((nums[n] % temp) == 0) {
                    nums[n] /= temp;
                    interval.first = (n < interval.first) ? n : interval.first;
                    interval.second = (interval.second < n) ? n : interval.second;
                }
            }
            if (interval.first != interval.second) {
                intervals.push_back(interval);
            }
        }

        sort(intervals.begin(), intervals.end(), compare());
        int ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            if ((intervals[i].first <= ans) && (ans < intervals[i].second)) {
                ans = intervals[i].second;
            }
        }
        if (nums.size() == ans + 1) {
            return -1;
        }
        else {
            return ans;
        }
    }
};