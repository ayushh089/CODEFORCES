#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bit_distance(int x) {
    string binary = "";
    while (x > 0) {
        binary = (x % 2 == 0 ? "0" : "1") + binary;
        x /= 2;
    }
    
    vector<int> indices;
    for (int i = 0; i < binary.length(); ++i) {
        if (binary[i] == '1') {
            indices.push_back(i);
        }
    }
    
    if (indices.size() < 2) {
        return -1;
    }
    
    int max_distance = 0;
    for (int i = 1; i < indices.size(); ++i) {
        max_distance = max(max_distance, indices[i] - indices[i - 1]);
    }
    
    return max_distance;
}

vector<int> getTopKBitDistances(vector<int>& numbers, int k) {
    vector<pair<int, int>> bit_distances;  
    
    for (int num : numbers) {
        bit_distances.push_back({num, bit_distance(num)});
    }
    
    sort(bit_distances.begin(), bit_distances.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second > b.second;
    });
    
    vector<int> result;
    for (int i = 0; i < k && i < bit_distances.size(); ++i) {
        result.push_back(bit_distances[i].first);
    }
    
    return result;
}

int main() {
    vector<int> numbers = {12,4,5,10,8};
    int k = 3;
    
    vector<int> result = getTopKBitDistances(numbers, k);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
