class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size () < 2) return 0;
        auto minVal = *min_element (nums.begin () , nums.end ());
        auto maxVal = *max_element (nums.begin () , nums.end ());
        if (maxVal - minVal <= 1) return maxVal - minVal;
        int bucketCount = (int)nums.size () - 1;
        int bucketSize = ceil ((double)(maxVal - minVal - 1) / bucketCount);
        vector <pair <int , int> > buckets (bucketCount , make_pair (INT_MAX , INT_MIN));
        for (auto num : nums) {
            if (num == minVal || num == maxVal) continue;
            int whichBucket = (num - minVal - 1) / bucketSize;
            buckets[whichBucket].first = min (buckets[whichBucket].first , num);
            buckets[whichBucket].second = max (buckets[whichBucket].second , num);
        }
        int maxGap = 0 , leftMax = minVal;
        for (auto bucket : buckets) {
            if (bucket.first == INT_MAX) continue;
            maxGap = max (maxGap , bucket.first - leftMax);
            leftMax = max (leftMax , bucket.second);
        }
        maxGap = max (maxGap , maxVal - leftMax);
        return maxGap;
    }
};