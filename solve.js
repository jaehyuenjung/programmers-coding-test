const input = {
    progresses: [
        [93, 30, 55],
        [95, 90, 99, 99, 80, 99],
    ],
    speeds: [
        [1, 30, 5],
        [1, 1, 1, 1, 1, 1],
    ],
    answer: [
        [2, 1],
        [1, 3, 2],
    ],
};

function solution(progresses, speeds) {
    let max_day = 0;
    return progresses.reduce((result, value, idx) => {
        const cur_day = parseInt((99 - progresses[idx]) / speeds[idx]) + 1;
        if (max_day < cur_day) {
            max_day = cur_day;
            result.push(1);
        } else {
            ++result[result.length - 1];
        }
        return result;
    }, []);
}

function test() {
    for (let i = 0; i < 2; i++) {
        const result = solution(input["progresses"][i], input["speeds"][i]);
        let output = "O";

        for (let j = 0; j < input["answer"][i].length; j++) {
            if (input["answer"][i][j] !== result[j]) {
                output = "X";
            }
        }

        console.log(output);
    }
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
