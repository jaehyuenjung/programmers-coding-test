const input = {
    priorities: [
        [2, 1, 3, 2],
        [1, 1, 9, 1, 1, 1],
    ],
    location: [2, 0],
    answer: [1, 5],
};

function solution(priorities, location) {
    let result = 0;
    let arr = priorities.map((priority, index) => ({ priority, index }));
    while (true) {
        const preEle = arr.shift();
        if (arr.some((el) => el.priority > preEle.priority)) {
            arr.push(preEle);
        } else {
            result++;
            if (preEle.index == location) {
                break;
            }
        }
    }
    return result;
}

function test() {
    for (let i = 0; i < 2; i++) {
        const result = solution(input["priorities"][i], input["location"][i]);

        if (input["answer"][i] === result) {
            console.log("O");
        } else {
            console.log("X");
        }
    }
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
