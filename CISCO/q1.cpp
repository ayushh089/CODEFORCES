#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

struct State {
    vector<int> jugs;
    int steps;
    
    bool operator<(const State& other) const {
        return jugs < other.jugs;
    }
};

int minSteps(vector<int>& capacities, vector<int>& start, vector<int>& goal) {
    set<vector<int>> visited;
    queue<State> q;
    q.push({start, 0});
    visited.insert(start);
    
    while (!q.empty()) {
        State current = q.front();
        q.pop();
        
        if (current.jugs == goal) {
            return current.steps;
        }
        
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i != j && current.jugs[i] > 0 && current.jugs[j] < capacities[j]) {
                    vector<int> next = current.jugs;
                    int transfer = min(current.jugs[i], capacities[j] - current.jugs[j]);
                    next[i] -= transfer;
                    next[j] += transfer;
                    
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push({next, current.steps + 1});
                    }
                }
            }
        }
    }
    
    return -1; // If no solution is found
}

int main() {
    vector<int> capacities = {13,12,10,5};
    vector<int> start = {6,6,0,0};
    vector<int> goal = {12,0,0,0};
    
    int steps = minSteps(capacities, start, goal);
    if (steps != -1) {
        cout << "Minimum steps required: " << steps << endl;
    } else {
        cout << "No solution found." << endl;
    }
    
    return 0;
}
