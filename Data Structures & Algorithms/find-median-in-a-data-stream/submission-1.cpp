class MedianFinder {
    priority_queue<int> smallerHalf;
    priority_queue<int,vector<int>,greater<int>> largerHalf;

public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(!largerHalf.empty() && num > largerHalf.top()) {
            largerHalf.push(num);
        } else {
            smallerHalf.push(num);
        }

        if(smallerHalf.size() > largerHalf.size() + 1) {
            largerHalf.push(smallerHalf.top());
            smallerHalf.pop();
        }
        if(largerHalf.size() > smallerHalf.size() + 1) {
            smallerHalf.push(largerHalf.top());
            largerHalf.pop();
        }
    }
    
    double findMedian() {
        if(smallerHalf.size() == largerHalf.size()) {
            return (smallerHalf.top() + largerHalf.top()) / 2.0;
        } else if (smallerHalf.size() > largerHalf.size()) {
            return smallerHalf.top();
        } else {
            return largerHalf.top();
        }
    }
};
