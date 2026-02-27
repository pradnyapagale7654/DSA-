#include <iostream>
using namespace std;

class solution {
public:
    int arr[100];
    int n;

    void input() {
        cout << "Enter size: ";
        cin >> n;
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Elements after sorting are: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Partition using while loops and first element as pivot
    int partitionFirstPivot(int a[], int low, int high) {
        int pivot = a[low];
        int i = low, j = high;

        while (i < j) {
            // Move j left until finding an element <= pivot
            while (i < j && a[j] > pivot)
                j--;
            // Move i right until finding an element > pivot
            while (i < j && a[i] <= pivot)
                i++;
            if (i < j)
                swap(a[i], a[j]);
        }
        // Place pivot at its correct position
        swap(a[low], a[j]);
        return j;
    }

    void quick(int a[], int low, int high) {
        if (low < high) {
            int p = partitionFirstPivot(a, low, high);
            quick(a, low, p - 1);
            quick(a, p + 1, high);
        }
    }

    void solve() {
        input();
        quick(arr, 0, n - 1);
        display();
    }
};

int main() {
    solution s;
   s. solve();
    return 0;
}
