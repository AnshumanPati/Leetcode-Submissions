class MedianFinder {

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::priority_queue<int> maxHeap;
    
public:
    void addNum(int num) {
        if (minHeap.empty() || num > minHeap.top()) {
            minHeap.push(num);
        } else {
            maxHeap.push(num);
        }
        
        // balance the heaps
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        } else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        } else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        } else {
            return maxHeap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */