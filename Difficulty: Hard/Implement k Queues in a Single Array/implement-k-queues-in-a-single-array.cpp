class kQueues {
    int *arr, *front, *rear, *next;
    int freeSpot, n, k;

public:
    kQueues(int n, int k) {
        this->n = n;
        this->k = k;

        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for(int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        for(int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        next[n - 1] = -1;
        freeSpot = 0;
    }

    bool isFull() {
        return freeSpot == -1;
    }

    bool isEmpty(int qi) {
        return front[qi] == -1;
    }

    void enqueue(int x, int qi) {
        if (isFull()) return;

        int index = freeSpot;
        freeSpot = next[index];

        if (isEmpty(qi))
            front[qi] = index;
        else
            next[rear[qi]] = index;

        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;
    }

    int dequeue(int qi) {
        if (isEmpty(qi)) return -1;

        int index = front[qi];
        front[qi] = next[index];

        if (front[qi] == -1)
            rear[qi] = -1;

        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};
