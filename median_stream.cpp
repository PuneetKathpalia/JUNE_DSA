class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int max_heap_size, min_heap_size;
    MedianFinder() {
        max_heap_size = 0;
        min_heap_size = 0;
    }
    
    void addNum(int num) {
       if(max_heap_size > min_heap_size) {
            //min_heap is the candidate
            max_heap.push(num);
            int ele = max_heap.top();
            max_heap.pop();
            min_heap.push(ele);
            min_heap_size++;
       } else {
            //max_heap is the candidate
            min_heap.push(num);
            int ele = min_heap.top();
            min_heap.pop();
            max_heap.push(ele);
            max_heap_size++;
       }
    }
    
    double findMedian() {
        if(max_heap_size > min_heap_size) {
            return max_heap.top();
        } else {
            int a = max_heap.top();
            int b = min_heap.top();
            return (double)(a+b)/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */