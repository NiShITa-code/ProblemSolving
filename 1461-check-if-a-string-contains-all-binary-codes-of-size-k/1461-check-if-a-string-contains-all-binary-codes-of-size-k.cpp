class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        
        // Total possible binary codes of length k = 2^k
        int totalCodes = 1 << k;
        
        // If the string does not even have enough substrings,
        // it's impossible to contain all binary codes.
        if (n - k + 1 < totalCodes)
            return false;

        // We use a boolean vector instead of unordered_set
        // because possible values range from 0 to (2^k - 1)
        vector<bool> seen(totalCodes, false);
        
        int current = 0;             // Stores current k-bit window as integer
        int mask = totalCodes - 1;   // This keeps only last k bits
                                     // Example: if k=3 → mask = 111 (binary)

        int count = 0; // Count of unique binary codes found

        for (int i = 0; i < n; i++) {
            
            // Step 1: Shift left to make room for new bit
            // Example: 101 -> 1010
            current = current << 1;
            
            // Step 2: Keep only last k bits using mask
            // This removes extra leftmost bit automatically
            // Example: 1010 & 111 = 010
            current = current & mask;
            
            // Step 3: Add current bit (0 or 1)
            // s[i] - '0' converts char to integer
            current = current | (s[i] - '0');
            
            // We only start checking once we have a full window of size k
            if (i >= k - 1) {
                // If this binary code hasn't been seen before
                if (!seen[current]) {
                    seen[current] = true;
                    count++;
                    
                    // If we've found all possible codes, return true
                    if (count == totalCodes)
                        return true;
                }
            }
        }
        
        // If we finish loop and haven't found all codes
        return false;
    }
        
    
};