#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    
    vector<int> stairs(N);
    for (int i = 0; i < N; i++) 
    {
        cin >> stairs[i];
    }
    
    cin >> Q;
    
    vector<int> heights(Q);
    for (int i = 0; i < Q; i++) {
        cin >> heights[i];
    }
    
    vector<int> steps(Q);
    for (int i = 0; i < Q; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) 
        {
            if (stairs[j] <= heights[i]) {
                count++;
            } else {
                break;
            }
        }
        steps[i] = count;
    }
    
    for (int i = 0; i < Q; i++) {
        cout << steps[i] << endl;
    }
    
    return 0;
}