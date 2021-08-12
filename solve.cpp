#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX_SIZE 100

struct Task{
    int progress;
    int speed;
    bool isComplete;
    Task() : progress(0), speed(0), isComplete(false){};
    Task(int progress, int speed) : progress(progress), speed(speed), isComplete(false){};
    int square() { return (((100 - progress) % speed) == 0) ? (100 - progress) / speed : (100 - progress) / speed + 1; }
};

using namespace std;
typedef vector<Task> vt;

const vector<vector<int>> inputProgresses = {{93, 30, 55}, {95, 90, 99, 99, 80, 99}};
const vector<vector<int>> inputSpeeds = {{1, 30, 5}, {1, 1, 1, 1, 1, 1}};
const vector<vector<int>> answer = {{2, 1}, {1, 3, 2}};

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int cur, count;
    cur = count = 0;
    vt tasks(progresses.size());
    vector<int> result(MAX_SIZE);
    fill(result.begin(), result.end(), 0);
    for (int i = 0; i < progresses.size(); i++)
        tasks[i] = Task(progresses[i], speeds[i]);
    
    while(count < tasks.size()){
        int maximum = 100;
        for (int i = 0; i < tasks.size(); i++){
            if(tasks[i].isComplete || tasks[i].progress >= 100)
                continue;
            maximum = min(maximum, tasks[i].square());
        }

        for (int i = 0; i < tasks.size(); i++)
        {
            if(tasks[i].isComplete)
                continue;
            tasks[i].progress += tasks[i].speed * maximum;
            if(tasks[i].progress >= 100 && ( i == 0 || tasks[i- 1].isComplete)){
                tasks[i].isComplete = true;
                result[cur]++;
                count++;
            }
        }
        if(result[cur])
            cur++;
    }

    return vector<int>(result.begin(), find(result.begin(), result.end(), 0));
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
