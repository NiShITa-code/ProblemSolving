class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> frequencyCount;
        int deletions = 0;
        set<int> frequencyUsed;
        
        for (char ch : s) {
            frequencyCount[ch]++;
        }
        
        for (auto& pair : frequencyCount) {
            int frequency = pair.second;
            while (frequency > 0 && frequencyUsed.find(frequency) != frequencyUsed.end()) {
                frequency--;
                deletions++;
            }
            frequencyUsed.insert(frequency);
        }
        
        return deletions;
    }
};