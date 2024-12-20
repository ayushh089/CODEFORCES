#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

void solve(int k, int n, vector<string> &passwords, string correct_passwd)
{
    int bc = 0, wc = 0;
    sort(passwords.begin(), passwords.end(), [](const string &a, const string &b)
         { return a.size() < b.size(); });
    int correctPasswordIndex = 0;
    map<int, int> mpp;
    for (auto it : passwords)
    {
        mpp[it.length()]++;
    }
    for (int i = 0; i < n; i++)
    {
        if ((passwords[i] == correct_passwd) || (passwords[i].size() == correct_passwd.size()))
        {
            correctPasswordIndex = i;
            break;
        }
    }
    if (correctPasswordIndex != 0)
        bc = correctPasswordIndex + 1 + (correctPasswordIndex) / k * 5;

    else
    {
        bc = 1;
    }
    int countTries = 0;
    for (auto it : mpp)
    {
        if (it.first <= correct_passwd.size())
        {
            countTries += it.second;
        }
    }
    wc = countTries + ((countTries - 1) / k) * 5;

    cout << bc << " " << wc << endl;
}

int main()
{
    int k, n;
    cin >> k >> n;

    vector<string> passwords(n);
    for (int i = 0; i < n; i++)
    {
        cin >> passwords[i];
    }

    string correct_passwd;
    cin >> correct_passwd;

    // Call the function to compute best and worst time
    solve(k, n, passwords, correct_passwd);

    return 0;
}
