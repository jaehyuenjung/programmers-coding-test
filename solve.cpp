#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const vvi inputJobs = {{0, 3}, {1, 9}, {2, 6}};
const int outputReturn = 9;

struct cmp1{
    const bool operator()(const vi &a, const vi &b){
        return a[0] > b[0];
    }
};

struct cmp2{
    const bool operator()(const vi &a, const vi &b){
        return a[1] > b[1];
    }
};


int solution(vvi jobs) {
    int time, total;
    time = total = 0;
    priority_queue<vi, vvi, cmp1> tasks(jobs.begin(), jobs.end());
    priority_queue<vi, vvi, cmp2> wait_tasks;
    while(!tasks.empty() || !wait_tasks.empty()){
        while(!tasks.empty() && tasks.top()[0] <= time){
            vi task = tasks.top();
            tasks.pop();
            wait_tasks.push(task);
        }
        if(!wait_tasks.empty()){
            vi task = wait_tasks.top();
            wait_tasks.pop();
            time += task[1];
            total += time - task[0];
        }else{
            time = tasks.top()[0];
        }
    }
    return total / jobs.size();
}

int main(){
    const int result = solution(inputJobs);
    if(outputReturn == result){
        cout << "O" << "\n";
    }else{
        cout << "X" << "\n";
    }
}
