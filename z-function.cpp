#include <bits/stdc++.h>
using namespace std;

vector<int> calcZ(string input)
{
    int n = input.length();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int k = 1; k < n; k++)
    {
        if (k > r)
        {
            l = r = k;
            while (r < n && input[r] == input[r - l])
            {
                r++;
            }
            z[k] = r - l;
            --r;
        }
        else
        {
            int k1 = k - l;
            if (z[k1] < r - k + 1)
            {
                z[k] = z[k1];
            }
            else
            {
                l = k;

                while (r < n && input[r] == input[r - l])
                {
                    r++;
                }
                z[k] = r - l;
                --r;
            }
        }
    }

    return z;
}

int countP(string pattern, string text)
{
    string input = pattern + "$" + text;
    int M = input.length();
    int N = text.length();
    vector<int> z = calcZ(input);
    for (auto it : z)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    string pattern = "abc";
    string text = "xabcabzabc";
    countP(pattern, text);
    return 0;
}