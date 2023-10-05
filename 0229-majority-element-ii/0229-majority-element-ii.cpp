class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1, ele2;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                count1++;
            } else if (count2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                count2++;
            }
            else if (nums[i] == ele1) {
                count1++;
            } else if(nums[i] == ele2) {
                count2++;
            } else {
                count1--;
                count2--;
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ele1) {
                cnt1++;
            }
            else if (nums[i] == ele2) {
                cnt2++;
            }
        } 
        vector<int> ls;
        int n =  nums.size();
        int mini = int(n / 3) + 1;
        if (cnt1 >= mini) ls.push_back(ele1);
        if (cnt2 >= mini) ls.push_back(ele2);  
        return ls;

    }
};