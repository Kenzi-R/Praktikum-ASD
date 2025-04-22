    #include <iostream>
    using namespace std;

    class Heap {
    private:
        int size;
        int capacity;
        int *arr;

        void heapify(int i);

    public:
        Heap(int capacity);
        ~Heap();
        void insertKey(int key);
        int top();
        int pop();
        void deleteKey(int key);
        void printHeap();
        void increaseKey(int oldValue, int newValue);
        void decreaseKey(int oldValue, int newValue);
    };

    // Constructor
    Heap::Heap(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        arr = new int[capacity];
    }

    // Destructor
    Heap::~Heap() {
        delete[] arr;
    }

    // Heapify function to maintain min-heap property
    void Heap::heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && arr[left] < arr[smallest])
            smallest = left;

        if (right < size && arr[right] < arr[smallest])
            smallest = right;

        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // Insert a new key into the heap
    void Heap::insertKey(int key) {
        if (size == capacity) {
            cout << "Overflow\n";
            return;
        }

        size++;
        int i = size - 1;
        arr[i] = key;

        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void Heap::increaseKey(int oldValue, int newValue) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == oldValue) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            cout << "Key not found\n";
            return;
        }
        if(arr[index]<newValue){
            arr[index] = newValue;

            while (index != 0 && arr[(index - 1) / 2] > arr[index]) {
                swap(arr[index], arr[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
    }

    void Heap::decreaseKey(int oldValue, int newValue) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == oldValue) {
                index = i;
                break;
            }
        }
        if(index == -1) {
            cout << "Key not found\n";
            return;
        }
        if(arr[index]>newValue){
            arr[index] = newValue;

            while (index != 0 && arr[(index - 1) / 2] > arr[index]) {
                swap(arr[index], arr[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
    }

    // Get the top (minimum) element of the heap
    int Heap::top() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return arr[0];
    }

    // Remove and return the top (minimum) element of the heap
    int Heap::pop() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }

        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);

        return root;
    }

    // Delete a specific key from the heap
    void Heap::deleteKey(int key) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Key not found\n";
            return;
        }
        if (index == size - 1) {
            size--;
            return;
        }
        arr[index] = arr[size - 1];
        size--;
        heapify(index);
    }

    // Print the heap   
    void Heap::printHeap() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    // Main function
    int main() {
        Heap heap(10);

        heap.insertKey(3);
        heap.insertKey(2);
        heap.insertKey(15);
        heap.insertKey(5);
        heap.insertKey(4);
        heap.insertKey(45);
        heap.insertKey(10);
        heap.insertKey(7);

        cout << "Heap after insertions:\n";
        heap.printHeap();

        cout << "Top element: " << heap.top() << "\n";

        cout << "Popped element: " << heap.pop() << "\n";

        cout << "Heap after pop:\n";
        heap.printHeap();

        cout << "Top element after pop: " << heap.top() << "\n";

        heap.deleteKey(15);
        cout << "Heap after deleting 15:\n";
        heap.printHeap();

        cout << "Top element after deletion: " << heap.top() << "\n";

        heap.increaseKey(5,8);
        cout << "Heap after increase key 5 to 8:\n";
        heap.printHeap();

        heap.increaseKey(1,100);
        cout << "Heap after increase key 1 to 100:\n";
        heap.printHeap();

        heap.decreaseKey(45,9);
        cout << "Heap after decrease key 45 to 9:\n";
        heap.printHeap();
        return 0;
    }