class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        // Smallest prime factor
        vector<int> spf(maxVal + 1);
        for (int i = 0; i <= maxVal; i++) spf[i] = i;

        for (long long i = 2; i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (long long j = i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        // Only primes that appear as nums[i] can be used for teleport
        vector<char> usefulPrime(maxVal + 1, false);

        for (int x : nums) {
            if (isPrime(x)) {
                usefulPrime[x] = true;
            }
        }

        // teleport[p] = indices j where nums[j] is divisible by p
        // only for useful primes p
        vector<vector<int>> teleport(maxVal + 1);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            while (x > 1) {
                int p = spf[x];

                if (usefulPrime[p]) {
                    teleport[p].push_back(i);
                }

                while (x % p == 0) {
                    x /= p;
                }
            }
        }

        queue<int> q;
        vector<int> dist(n, -1);
        vector<char> usedPrime(maxVal + 1, false);

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            // left
            if (i - 1 >= 0 && dist[i - 1] == -1) {
                dist[i - 1] = dist[i] + 1;
                q.push(i - 1);
            }

            // right
            if (i + 1 < n && dist[i + 1] == -1) {
                dist[i + 1] = dist[i] + 1;
                q.push(i + 1);
            }

            int p = nums[i];

            // teleport only if nums[i] is prime and not used before
            if (isPrime(p) && !usedPrime[p]) {
                usedPrime[p] = true;

                for (int j : teleport[p]) {
                    if (dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                        q.push(j);
                    }
                }
            }
        }

        return dist[n - 1];
    }
};