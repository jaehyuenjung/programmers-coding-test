const input = {
    jobs: [
        [0, 3],
        [1, 9],
        [2, 6],
    ],
    return: 9,
};

function solution(jobs) {
    let time = 0;
    let total = 0;
    const size = jobs.length;
    jobs.sort((a, b) => a[1] - b[1]);
    while (jobs.length) {
        for (let i = 0; i < jobs.length; i++) {
            if (jobs[i][0] <= time) {
                time += jobs[i][1];
                total += time - jobs[i][0];
                jobs.splice(i, 1);
                break;
            }

            if (i == jobs.length - 1) time++;
        }
    }
    return Math.floor(total / size);
}

function test() {
    const result = solution(input["jobs"]);
    if (input["return"] === result) {
        console.log("O");
    } else {
        console.log("X");
    }
    console.log(result);
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
