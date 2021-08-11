#include<iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <queue>
#define fst first
#define snd second

struct Music{
    int id;
    int playCount;
    Music() : id(0), playCount(0){};
    Music(int id, int playCount) : id(id), playCount(playCount){};
};

struct cmp{
    bool operator()(const Music &a,const Music &b){
        if(a.playCount != b.playCount)
            return a.playCount < b.playCount;
        return a.id > b.id;
    }
};

using namespace std;
typedef size_t st;
typedef map<string, int> msi;
typedef pair<string, int> psi;
typedef priority_queue<Music,vector<Music>, cmp> pqm;
typedef map<string, pqm> mspqm;
typedef pair<string, pqm> pspqm;

const bool compare(const psi &a, const psi &b){
    return a.snd > b.snd;
}

const vector<string> inputGenres = {"classic", "pop", "classic", "classic","jazz","pop", "Rock", "jazz"};
const vector<int> inputPlays = {500, 600, 150, 800, 1100, 2500, 100, 1000};
const vector<int> answer = {5, 1, 4, 7, 3, 0, 6};

vector<int> solution(vector<string> genres, vector<int> plays) {
    msi hashMap;
    mspqm hashMapDetail;
    for (st i = 0; i < genres.size(); i++){
        hashMap[genres[i]] += plays[i];
        hashMapDetail[genres[i]].push(Music(i, plays[i]));
    }
    vector<psi> hashMapCopy(hashMap.begin(), hashMap.end());
    sort(hashMapCopy.begin(), hashMapCopy.end(), compare);
    return accumulate(hashMapCopy.begin(), hashMapCopy.end(), vector<int>(), [&](vector<int> &result, const psi &value){  
        pqm q = hashMapDetail[value.fst];
        int l = q.size() - 2;
        while (!q.empty() && l < (int)q.size())
        {
            result.push_back(q.top().id);
            q.pop();
        }
        return result;
    });
}

int main(){
    const vector<int> result = solution(inputGenres, inputPlays);

    string str = "O";
    for (int i = 0; i < 7; i++){
        if(result[i] != answer[i]){
            str = "X";
        }

        // cout << result[i] << "\n";
    }

    cout << str << "\n";
}
