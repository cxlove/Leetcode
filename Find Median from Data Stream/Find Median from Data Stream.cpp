class MedianFinder {
public:
    MedianFinder () {
        small = large = 0;
        while (!left.empty ()) left.pop ();
        while (!right.empty ()) right.pop ();
    }
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if (!small || num <= left.top ()) {
            left.push (num);small ++;
        }
        else {
            right.push (num);large ++;
        }
        while (small > large + 1) {
            right.push (left.top ());
            left.pop ();
            small --;large ++;
        }
        while (large > small) {
            left.push (right.top ());
            right.pop ();
            small ++;large --;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (small == large) return (left.top () + right.top ()) / 2.0;
        return left.top ();
    }
private :
    int small , large;
    priority_queue <int> left;
    priority_queue <int , vector<int> , greater <int> > right;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();