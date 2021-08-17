#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const vector<vector<int>> inputProrities = {{2, 1, 3, 2}, {1, 1, 9, 1, 1, 1}};
const vector<int> inputLocation = {2, 0};
const vector<int> answer = {1, 5};

int solution(vector<int> priorities, int location) {
    int result = 0;
    queue<pair<int,int>> q;

    for(int i=0; i<priorities.size(); i++) {
        q.push(make_pair(i, priorities[i]));
    }

    sort(priorities.begin(), priorities.end(), greater<int>());

    int t = 0;
    while(!q.empty()) {
        int i = q.front().first;
        int p = q.front().second;
        q.pop();
        
        if(p == priorities[t]) {
            t++;
            result++;
            if(i == location)
                break;
        }else{
            q.push(make_pair(i,p));
        }
    }
    return result;
}

int main(){
    for (int i = 0; i < 2; i++){
        const int result = solution(inputProrities[i], inputLocation[i]);

        if(result == answer[i])
            cout << "O"
                 << "\n";
        else
            cout << "X"
                 << "\n";
    }
}
