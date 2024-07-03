#include <iostream>
#include <vector>

using namespace std;

int max_operations(vector<int>& a) {
    int n = a.size();
    int operations = 0;

    int i = 0;
    while (i < n - 1) {
        if (a[i] == i + 1) {
            operations++;
            i += 2; // Skip a[i] and a[i+1]
        } else {
            i++; // Move to the next element
        }
    }

    return operations;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int result = max_operations(a);
        cout << result << endl;
    }

    return 0;
}
