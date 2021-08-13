#include<iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

const vector<vector<int>> inputProgresses = {{93, 30, 55}, {95, 90, 99, 99, 80, 99}};
const vector<vector<int>> inputSpeeds = {{1, 30, 5}, {1, 1, 1, 1, 1, 1}};
const vector<vector<int>> answer = {{2, 1}, {1, 3, 2}};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int max_day, idx;
    max_day = idx = 0;
    return accumulate(progresses.begin(), progresses.end(), vector<int>(), [&](vector<int> &result,const int value) {
        int cur_day = (99 - progresses[idx]) / speeds[idx] + 1;
        if(max_day < cur_day)
            result.push_back(1);
        else
            ++result.back();
        max_day = max(max_day, cur_day);
        idx++;
        return result;
    });
}

int main(){
    for (int i = 0; i < 2; i++){
        vector<int> result = solution(inputProgresses[i], inputSpeeds[i]);
        
        string output = "O";
        for (int j = 0; j < answer[i].size(); j++){
            if(answer[i][j] != result[j]){
                output = "X";
            }
        }

        cout << output << "\n";
    }
}
