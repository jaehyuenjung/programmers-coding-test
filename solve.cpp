#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const vector<int> inputBridgeLength = {2, 100, 100};
const vector<int> inputWeight = {10, 100, 100};
const vector<vector<int>> inputTruckWeights = {{7, 4, 5, 6}, {10}, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}};
const vector<int> answer = {8, 101, 110};

class Truck{
    public:
        int idx;
        int loc;
        Truck(int idx, int loc){
            this->idx = idx;
            this->loc = loc;
        }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int next_idx, total_weight, result;
    next_idx = total_weight = result = 0;
    vector<Truck*> trucks(truck_weights.size());
    queue<Truck*> bridge;

    for (int i = 0; i < trucks.size(); i++){
        trucks[i] = new Truck(i,0);
    }

    while (next_idx < truck_weights.size() || !bridge.empty())
    {
        if (bridge.empty() && next_idx < truck_weights.size())
        {
             total_weight += truck_weights[next_idx];
            bridge.push(trucks[next_idx]);
            trucks[next_idx]->loc++;
            next_idx++;
        }
        else{
            Truck *fst_truck = bridge.front();
            for (int i = 0; i < next_idx; i++)
                trucks[i]->loc++;
            if(fst_truck->loc > bridge_length){
                total_weight -= truck_weights[fst_truck->idx];
                bridge.pop();
            }
            if(next_idx < truck_weights.size() && total_weight + truck_weights[next_idx] <= weight){
                total_weight += truck_weights[next_idx];
                bridge.push(trucks[next_idx]);
                trucks[next_idx]->loc++;
                next_idx++;
            }
        }
        result++;
    }

    return result;
}

int main(){
    for (int i = 0; i < 3; i++){
        int result = solution(inputBridgeLength[i], inputWeight[i], inputTruckWeights[i]);
        if(result == answer[i])
            cout << "O" << "\n";
        else
            cout << "X" << "\n";
        cout << result << "\n";
    }
}
