#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void insertHeap(vector<int> &heap, int val);
void deleteRoot(vector<int> &heap);
void buildHeap(vector<int> &heap);
int peek(vector<int> &heap);
void heapify(vector<int> &heap, int n, int i);

void printHeap(vector<int> &heap)
{
    for (int x : heap)
        cout << x << " ";
    cout << endl;
}

int main()
{
    vector<int> heap;

    // 🔸 Build Heap from array
    heap = {10, 30, 20, 5, 40};
    cout << "Original array: ";
    printHeap(heap);

    buildHeap(heap);
    cout << "After buildHeap: ";
    printHeap(heap);

    // 🔸 Insert element
    cout << "Inserting 50..." << endl;
    insertHeap(heap, 50);
    printHeap(heap);

    // 🔸 Peek (get max)
    cout << "Top element (peek): " << peek(heap) << endl;

    // 🔸 Delete root
    cout << "Deleting root..." << endl;
    deleteRoot(heap);
    printHeap(heap);

    return 0;
}

void insertHeap(vector<int> &heap, int val)
{
    heap.push_back(val);
    int i = heap.size() - 1;

    while (i > 0)
    {
        int parent = (i - 1) / 2;

        if (heap[parent] > heap[i])
        {
            swap(heap[parent], heap[i]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void deleteRoot(vector<int> &heap)
{
    if (heap.empty())
        return;
    int n = heap.size() - 1;
    swap(heap[0], heap[n]);
    heap.pop_back();

    int i = 0;
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < heap.size() && heap[smallest] > heap[left])
        {
            smallest = left;
        }
        if (right < heap.size() && heap[smallest] > heap[right])
        {
            smallest = right;
        }
        if (smallest != i)
        {
            swap(heap[smallest], heap[i]);
            i = smallest;
        }
        else
        {
            break;
        }
    }
}

void heapify(vector<int> &heap, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && heap[smallest] > heap[left])
    {
        smallest = left;
    }
    if (right < n && heap[smallest] > heap[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(heap[smallest], heap[i]);
        heapify(heap, n, smallest);
    }
}

void buildHeap(vector<int> &heap)
{
    int n = heap.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(heap, n, i);
    }
}

int peek(vector<int> &heap)
{
    if (heap.empty())
    {
        return -1;
    }
    return heap[0];
}