const input = {
    participant: [
        ["leo", "kiki", "eden"],
        ["marina", "josipa", "nikola", "vinko", "filipa"],
        ["mislav", "stanko", "mislav", "ana"],
    ],
    completion: [
        ["eden", "kiki"],
        ["josipa", "filipa", "marina", "nikola"],
        ["stanko", "ana", "mislav"],
    ],
    answer: ["leo", "vinko", "mislav"],
};

function solution(participant, completion) {
    const check = {};
    participant.forEach((element) => (check[element] = 0));
    participant.forEach((element) => check[element]++);
    completion.forEach((element) => check[element]--);
    return Object.keys(check).filter((element) => check[element] > 0)[0];
}

function test() {
    input["answer"].forEach((element, idx) => {
        const result = solution(
            input["participant"][idx],
            input["completion"][idx]
        );
        if (element === result) {
            console.log("O");
        } else {
            console.log("X");
        }
    });
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
