class NumArray {
public:
    vector <int> a , s;
    NumArray(vector<int> &nums) {
        a = nums;
        s.resize (nums.size () , 0);
        for (int i = 0 ; i < (int)nums.size () ; i ++) {
            add (i + 1 , nums[i]);
        }
    }

    void add (int i, int val) {
        for (int x = i ; x <= (int)a.size () ; x += x & (-x)) {
            s[x - 1] += val;
        }
    }
    
    int ask (int i) {
        int sum = 0;
        for (int x = i ; x > 0 ; x -= x & (-x)) {
            sum += s[x - 1];
        }
        
        return sum;
    }
    
    void update(int i, int val) {
        add (i + 1 , -a[i]);
        a[i] = val;
        add (i + 1 , val);
    }

    int sumRange(int i, int j) {
        return ask (j + 1) - ask (i);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);