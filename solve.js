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
    const trucks = truck_weights.map((weight, idx) => ({
        idx,
        weight,
        loc: 0,
        is_gone: false,
    }));
    while (trucks.some((el) => !el["is_gone"])) {
        const truck = trucks.find((el) => !el["is_gone"] && !el["loc"]);
        queue = queue.map((el) => {
            ++el["loc"];
            return el;
        });

        if (queue.length && queue[0]["loc"] > bridge_length) {
            const remove_truck = queue.shift();
            total_weight -= remove_truck["weight"];
            trucks[remove_truck["idx"]]["is_gone"] = true;
        }
        if (
            trucks.some((el) => !el["is_gone"]) &&
            truck &&
            (queue.length == 0 || total_weight + truck["weight"] <= weight)
        ) {
            total_weight += truck["weight"];
            truck["loc"]++;
            queue.push(truck);
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
