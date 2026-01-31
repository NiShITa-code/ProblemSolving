class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
            // letters array is sorted in non decreasing order we can do binary search in O(logn) to find the smalllesr letter gretaer than target
        int left = 0, right = letters.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (letters[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }
        // if we have such chr left will point to that char otherwise If left == size → index becomes 0 Returns the first character in letters
        return letters[left % letters.size()];

        
    }
};