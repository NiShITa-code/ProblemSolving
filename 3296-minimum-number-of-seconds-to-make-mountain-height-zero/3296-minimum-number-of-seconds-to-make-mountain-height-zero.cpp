class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        using T = tuple<long long, long long, long long>;
        priority_queue<T, vector<T>, greater<T>> pq;
        for (int w: workerTimes) {
            pq.push({w, w, 1});
        }
        long long ans = 0;
        // in ecah iteration we remove 1 unit from mountain
        for (int i = 0; i < mountainHeight; i++) {
            // use the one with smalllest finish time
            auto [finishTime, w, k] = pq.top();
            pq.pop();
            ans = finishTime;
            // since it has alreday processed its kth unit if its used to processnext unit this will be the new finish time
            long long nextFinish = finishTime + w * (k + 1);
            pq.push({nextFinish, w, k + 1});

        }
        return ans;
        
    }
};