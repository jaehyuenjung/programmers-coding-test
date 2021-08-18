const input = {
    bridge_length: [2, 100, 100],
    weight: [10, 100, 100],
    truck_weights: [
        [7, 4, 5, 6],
        [10],
        [10, 10, 10, 10, 10, 10, 10, 10, 10, 10],
    ],
    answer: [8, 101, 110],
};

function solution(bridge_length, weight, truck_weights) {
    let time = 0;
    let total_weight = 0;
    let queue = [];

    queue.push({ weight: 0, loc: 0 });
    while (queue.length || truck_weights.length) {
        if (queue[0]["loc"] === time) total_weight -= queue.shift()["weight"];
        if (total_weight + truck_weights[0] <= weight) {
            total_weight += truck_weights[0];
            queue.push({
                weight: truck_weights.shift(),
                loc: time + bridge_length,
            });
        } else {
            if (queue[0]) time = queue[0]["loc"] - 1;
        }
        time++;
    }
    return time;
}

function test() {
    for (let i = 0; i < 3; i++) {
        const result = solution(
            input["bridge_length"][i],
            input["weight"][i],
            input["truck_weights"][i]
        );

        if (result === input["answer"][i]) {
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
