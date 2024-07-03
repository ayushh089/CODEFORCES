#include <bits/stdc++.h>
using namespace std;
string distance_finder(string str, int start, int end)
{
    return str.substr(start, end - start+1);
}
int main()
{
    // cout << __builtin_popcount(5);
    // return 0;
    string s="HeyAyush";
    cout<<distance_finder(s,1,1);
}