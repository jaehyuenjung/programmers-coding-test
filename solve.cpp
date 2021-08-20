#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const vector<int> inputScoville = {1, 2, 3, 9, 10, 12};
const int inputK = 7;
const int outputReturn = 2;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.size() > 1 && pq.top() < K){
        int k_food_one = pq.top();
        pq.pop();
        int k_food_two = pq.top();
        pq.pop();
        pq.push(k_food_one + (k_food_two * 2));
        answer++;
    }
    return (pq.top() < K)? -1 : answer;
}

int main(){
    const int result = solution(inputScoville, inputK);
    if(outputReturn == result){
        cout << "O"<< "\n";
    }else{
        cout << "X" << "\n";
    }
}
