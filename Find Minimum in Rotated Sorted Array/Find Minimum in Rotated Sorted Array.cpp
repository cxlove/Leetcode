class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0 , high = (int)nums.size () - 1 , ans = nums[0];
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (nums[mid] >= nums[low] && nums[mid] <= nums[high]) {
                return min (ans , nums[low]);
            } 
            else if (nums[mid] >= nums[low] && nums[mid] >= nums[high]) {
                low = mid + 1;
            }
            else {
                ans = min (ans , nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};