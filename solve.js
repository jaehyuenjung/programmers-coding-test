const input = {
    answers: [
        [1, 2, 3, 4, 5],
        [1, 3, 2, 4, 2],
    ],
    return: [[1], [1, 2, 3]],
};

function solution(answers) {
    const answer = [];
    const result = [0, 0, 0];
    const supoja1 = [1, 2, 3, 4, 5];
    const supoja2 = [2, 1, 2, 3, 2, 4, 2, 5];
    const supoja3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    let max_value = 0;
    for (let i = 0; i < answers.length; i++) {
        if (supoja1[i % supoja1.length] === answers[i]) result[0]++;
        if (supoja2[i % supoja2.length] === answers[i]) result[1]++;
        if (supoja3[i % supoja3.length] === answers[i]) result[2]++;
        max_value = Math.max(max_value, ...result);
    }
    for (let i = 0; i < result.length; i++)
        if (result[i] === max_value) answer.push(i + 1);
    return answer;
}

function test() {
    for (let i = 0; i < 2; i++) {
        const result = solution(input["answers"][i]);
        let ouput = "O";
        for (let j = 0; j < input["return"][i].length; j++) {
            if (input["return"][i][j] !== result[j]) {
                output = "X";
                break;
            }
        }
        console.log(ouput);
    }
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
