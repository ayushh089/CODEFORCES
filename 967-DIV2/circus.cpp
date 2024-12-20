#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1e9 + 7;

int solve(int k, vector<int> &weights)
{
    // Sort the weights in ascending order
    sort(weights.begin(), weights.end());

    int trips = 0;
    int curSum = 0;

    // Take the smallest weight first and add it to curSum
    curSum = weights[0];
    trips++; // This small person will need at least one trip

    // Loop from the last element (heaviest) towards the first
    int i = weights.size() - 1; // start from the largest
    while (i > 0)
    { // until we process all larger weights
        if (curSum + weights[i] <= k)
        {
            // Add the heaviest person that can fit without exceeding the capacity
            curSum += weights[i];
            i--; // Move to the next largest person
        }
        else
        {
            // If adding the next person exceeds capacity, make a new trip
            trips++;
            trips++;
            curSum = weights[0]; // Start again with the smallest weight in curSum
        }
    }

    return trips;
}
int solve1(int k, vector<int> &weights)
{
    // Sort the weights in ascending order
      sort(weights.begin(), weights.end());

    int n = weights.size();
    vector<int> dp(n + 1, 0); // DP array to store number of ways
    dp[0] = 1; // There's one way to partition 0 elements

    // Calculate the number of ways to partition
    for (int i = 0; i < n; i++) {
        int curSum = 0;

        // Try to add weights from i back to j
        for (int j = i; j >= 0; j--) {
            curSum += weights[j];

            if (curSum > k) break; // Can't add more if we exceed the limit
            
            // If valid, update the number of ways to partition up to i+1
            dp[i + 1] = (dp[i + 1] + dp[j]) % MOD;
        }
    }

    // Minimum number of trips can be determined by looking at the last group
    int trips = 0;
    int curSum = 0;

    for (int i = n - 1; i >= 0; i--) {
        curSum += weights[i];
        if (curSum > k) {
            trips++;
            curSum = weights[i];
        }
    }

    // Don't forget to count the last trip
    if (curSum > 0) {
        trips++;
    }

    // cout << "Number of ways to partition: " << dp[n] << endl;

    return dp[n];
}
int main()
{
    int k, n;
    cin >> k >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int result = solve(k, weights);
    int result1 = solve1(k, weights);
    cout << result << " " << result1 << endl;

    return 0;
}
