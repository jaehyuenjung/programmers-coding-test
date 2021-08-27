#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const vector<vector<int>> inputAnswers = {{1, 2, 3, 4, 5}, {1, 3, 2, 4, 2}};
const vector<vector<int>> outputReturn = {{1}, {1, 2, 3}};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> result(3);
    fill(result.begin(), result.end(), 0);
    vector<int> supoja1 = {1, 2, 3, 4, 5};
    vector<int> supoja2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> supoja3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int max_value = 0;
    for (int i = 0; i < answers.size(); i++){
        if(supoja1[i%supoja1.size()] == answers[i])
            result[0]++;
        if(supoja2[i%supoja2.size()] == answers[i])
            result[1]++;
        if(supoja3[i%supoja3.size()] == answers[i])
            result[2]++;
        max_value = max(max_value, max(result[0], max(result[1], result[2])));
    }
    for (int i = 0; i < 3; i++)
        if(result[i] == max_value)
            answer.push_back(i + 1);
    return answer;
}

int main(){
    for (int i = 0; i < 2; i++){
        const vector<int> result = solution(inputAnswers[i]);
        string output = "O";
        for (int j = 0; j < outputReturn[i].size(); j++){
            if(outputReturn[i][j] != result[j]){
                output = "X";
                break;
            }
        }
        cout << output << "\n";
    }
}
