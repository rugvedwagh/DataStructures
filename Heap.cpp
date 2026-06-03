class MinHeap {
private:
    vector<int> heap;

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;

            if (heap[parent] <= heap[idx])
                break;

            swap(heap[parent], heap[idx]);
            idx = parent;
        }
    }

    void heapifyDown(int idx) {
        int n = heap.size();

        while (true) {
            int smallest = idx;
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == idx)
                break;

            swap(heap[idx], heap[smallest]);
            idx = smallest;
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);
    }

    int top() { return heap[0]; }

    bool empty() { return heap.empty(); }
};
