const input = {
    array: [1, 5, 2, 6, 3, 7, 4],
    commands: [
        [2, 5, 3],
        [4, 4, 1],
        [1, 7, 3],
    ],
    return: [5, 6, 3],
};

function solution(array, commands) {
    const answer = [];
    commands.forEach((el) => {
        answer.push(array.slice(--el[0], el[1]).sort((a, b) => a - b)[--el[2]]);
    });
    return answer;
}

function test() {
    const result = solution(input["array"], input["commands"]);
    let output = "O";
    for (let i = 0; i < input["return"].length; i++) {
        if (input["return"][i] !== result[i]) {
            output = "X";
        }
    }
    console.log(output);
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
