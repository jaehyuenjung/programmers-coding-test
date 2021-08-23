const input = {
    operations: [
        ["I 16", "D 1"],
        ["I 7", "I 5", "I -5", "D -1"],
    ],
    return: [
        [0, 0],
        [7, 5],
    ],
};

function solution(operations) {
    const dq = [];
    while (operations.length) {
        let comm;
        let number;
        while (operations.length && comm !== "D") {
            [comm, number] = operations.shift().split(" ");
            number = parseInt(number);

            if (comm === "I") {
                dq.push(number);
            }
        }
        dq.sort((a, b) => b - a);

        if (comm === "D" && dq.length) {
            if (number > 0) {
                dq.shift();
            } else {
                dq.splice(dq.length - 1, 1);
            }
        }
    }
    return dq.length ? [dq.shift(), dq[dq.length - 1]] : [0, 0];
}

function test() {
    for (let i = 0; i < 2; i++) {
        const result = solution(input["operations"][i]);
        let output = "O";
        for (let j = 0; j < result.length; j++) {
            if (input["return"][i][j] !== result[j]) {
                output = "X";
            }
            console.log(result[j]);
        }

        console.log(output);
    }
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
