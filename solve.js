const input = {
    prices: [1, 2, 3, 2, 3],
    return: [4, 3, 1, 1, 0],
};

function solution(prices) {
    time_stamp = [];
    answer = [];
    time_stamp[prices.length - 1] = prices.length;
    answer[prices.length - 1] = 0;
    for (let i = prices.length - 2; i >= 0; i--) {
        if (prices[i] <= prices[i + 1]) {
            answer[i] = answer[i + 1] + 1;
            time_stamp[i] = time_stamp[i + 1];
            while (
                time_stamp[i] < prices.length &&
                prices[i] <= prices[time_stamp[i]]
            ) {
                answer[i] += answer[time_stamp[i]];
                time_stamp[i] = time_stamp[time_stamp[i]];
            }
        } else {
            answer[i] = 1;
            time_stamp[i] = i + 1;
        }
    }
    return answer;
}

function test() {
    const result = solution(input["prices"]);

    let output = "O";
    for (let i = 0; i < input["return"].length; i++) {
        if (input["return"][i] !== result[i]) {
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
