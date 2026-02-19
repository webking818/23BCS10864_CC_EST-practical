#include <iostream>
#include <vector>
using namespace std;

int sumOfBitDifferences(const vector<int>& arr) {
    int n = arr.size();
    long long total = 0;
    for (int bit = 0; bit < 32; bit++) {
        int ones = 0;

        for (int num : arr) {
            if (num & (1 << bit))
                ones++;
        }

        int zeros = n - ones;
        total += 2LL * ones * zeros;
    }

    return total;
}

int main() {
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 3};

    cout << sumOfBitDifferences(arr1) << endl; // Output: 8
    cout << sumOfBitDifferences(arr2) << endl; // Output: 2

    return 0;
}
