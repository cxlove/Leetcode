class Solution {
public:
    int removeDuplicates(int A[], int n) {
        sort (A , A + n);
        int m = unique (A , A + n) - A;
        return m
    }
};