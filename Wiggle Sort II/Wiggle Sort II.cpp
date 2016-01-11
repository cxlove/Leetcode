class Solution {
public:
    int newIdx (int i , const int mid , const int n) {
        if (i < mid) return (mid - 1 - i) * 2;
        else return (n - 1 - i) * 2 + 1;
    }
    void wiggleSort(vector<int>& nums) {
        vector <int> :: iterator mid = nums.begin () + nums.size () / 2;
        nth_element (nums.begin () , mid , nums.end ());
        int val = *mid;
        for (vector <int> :: size_type l = 0 , r = nums.size () - 1 , m = 0 ; m <= r ;) {
            if (nums[m] < val) {
                swap (nums[m ++] , nums[l ++]);
            }
            else if (nums[m] > val) {
                swap (nums[m] , nums[r --]);
            }
            else m ++;
        }

        for (vector <int> :: size_type i = 0 ; i < nums.size () ; i ++) {
            nums[i] *= -1;
        }
        
        int partition = ((int)nums.size () + 1) / 2;
        for (vector <int> :: size_type i = 0 ; i < nums.size () ; i ++) {
            if (nums[i] < 0) {
                int p = i;
                while (true) {
                    p = newIdx (p , partition , nums.size ());
                    if (p == i) break;
                    swap (nums[p] , nums[i]);
                    nums[p] *= -1;
                }
                nums[i] *= -1;
            }
        }
    }
};
