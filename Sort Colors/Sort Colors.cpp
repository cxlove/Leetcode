
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int)nums.size ();
        int two = n - 1 , zero = 0;
        for (int i = zero ; i <= two ; i ++) {
            while (nums[zero] == 0) zero ++;
            while (nums[two] == 2) two --;
            i = max (i , zero);
            if (i > two) break;
            if (nums[i] == 2) {
                swap (nums[two --] , nums[i --]);
            }
            else if (nums[i] == 0) {
                swap (nums[zero ++] , nums[i --]);
            }
        }
    }
};