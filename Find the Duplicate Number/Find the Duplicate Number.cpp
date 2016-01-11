class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0 , fast = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }
        int origin = 0;
        while (true) {
            slow = nums[slow];
            origin = nums[origin];
            if (slow == origin) return origin;
        }
    }
};
