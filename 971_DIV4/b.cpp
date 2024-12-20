#include <bits/stdc++.h>
using namespace std;

int f( string &s) {
     int n = s.length();
    unordered_set<int> all, e;
    for (char c : s) {
        int v = 1 << (c - 'a');
        unordered_set<int> temp = {v};
        for (int x : e) {
            temp.insert(x | v);
        }
        e.clear();
        for (int x : temp) {
            e.insert(x);
            all.insert(x);
        }
    }
    return all.size();
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // cout<<count_sets(n,s)<<endl;

        cout << f(s) << endl;
    }

    return 0;
}