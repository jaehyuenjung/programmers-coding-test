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
    let hashMap = {};
    const hashMapDetail = {};
    for (let i = 0; i < genres.length; i++) {
        hashMap[genres[i]] =
            (hashMap[genres[i]] ? hashMap[genres[i]] : 0) + plays[i];
        const pre = hashMapDetail[genres[i]] ? hashMapDetail[genres[i]] : [];
        pre.push({ id: i, playCount: plays[i] });
        hashMapDetail[genres[i]] = pre;
    }

    hashMap = Object.fromEntries(
        Object.entries(hashMap).sort(([, a], [, b]) => b - a)
    );
    return Object.keys(hashMap).reduce((result, key) => {
        hashMapDetail[key]
            .sort((a, b) => {
                if (a.playCount !== b.playCount) {
                    return b.playCount - a.playCount;
                }
                return a.id - b.id;
            })
            .forEach(({ id }, idx) => {
                if (idx < 2) {
                    result.push(id);
                }
            });
        return result;
    }, []);
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
