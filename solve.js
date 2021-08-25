const input = {
    numbers: [
        [6, 10, 2],
        [3, 30, 34, 5, 9],
    ],
    return: ["6210", "9534330"],
};

function solution(numbers) {
    numbers = numbers.map((el) => String(el));
    numbers = numbers.sort((a, b) => b + a - (a + b));
    console.log(numbers);
    if (numbers[0] === "0") return "0";
    return numbers.reduce((result, value) => result + value, "");
}

function test() {
    for (let i = 0; i < 2; i++) {
        const result = solution(input["numbers"][i]);
        if (input["return"][i] === result) {
            console.log("O");
        } else {
            console.log("X");
        }
        console.log(result);
    }
}

let start = new Date(); // 시작
test();
let end = new Date(); // 종료

console.log("----------테스트 실행 완료----------");
console.log(`걸린 시간: ${(end - start) / 1000}sec`);
