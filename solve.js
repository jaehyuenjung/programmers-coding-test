const input = {
    genres: [
        "classic",
        "pop",
        "classic",
        "classic",
        "jazz",
        "pop",
        "Rock",
        "jazz",
    ],
    plays: [500, 600, 150, 800, 1100, 2500, 100, 1000],
    answer: [5, 1, 4, 7, 3, 0, 6],
};

function solution(genres, plays) {
    const hashMap = {};
    const hashMapDic = {};
    genres.forEach((e, i) => (hashMap[e] = (hashMap[e] | 0) + plays[i]));
    return genres
        .map((genre, i) => ({ id: i, playCount: plays[i], genre }))
        .sort((a, b) => {
            if (a.genre !== b.genre) {
                return hashMap[b.genre] - hashMap[a.genre];
            }
            if (a.playCount !== b.playCount) {
                return b.playCount - a.playCount;
            }
            return a.id - b.id;
        })
        .filter(({ genre }) => {
            if (hashMapDic[genre] >= 2) {
                return false;
            }
            hashMapDic[genre] = (hashMapDic[genre] | 0) + 1;
            return true;
        })
        .map(({ id }) => id);
}

function test() {
    const result = solution(input.genres, input.plays);
    let output = "O";
    for (let i = 0; i < input.answer.length; i++) {
        if (input.answer[i] !== result[i]) {
            output = "X";
            break;
        }
    }
    console.log(output);
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
