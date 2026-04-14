class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (valueDiff < 0) return false;

        unordered_map<long long, long long> bucket;
        long long w = (long long)valueDiff + 1;

        for (int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            long long id = x / w;

            if (x < 0) id--; // fix negative bucket

            // same bucket
            if (bucket.count(id)) return true;

            // neighbor buckets
            if (bucket.count(id - 1) && abs(x - bucket[id - 1]) < w)
                return true;

            if (bucket.count(id + 1) && abs(x - bucket[id + 1]) < w)
                return true;

            bucket[id] = x;

            // remove out-of-range index
            if (i >= indexDiff) {
                long long old = nums[i - indexDiff];
                long long oldId = old / w;
                if (old < 0) oldId--;
                bucket.erase(oldId);
            }
        }

        return false;
    }
};