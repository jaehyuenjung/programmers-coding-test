const input = {
    clothes: [
        [
            ["yellowhat", "headgear"],
            ["bluesunglasses", "eyewear"],
            ["green_turban", "headgear"],
        ],
        [
            ["crowmask", "face"],
            ["bluesunglasses", "face"],
            ["smoky_makeup", "face"],
        ],
    ],
    answer: [5, 3],
};

function solution(clothes) {
    const hash_map = {};
    clothes.forEach(
        (element) =>
            (hash_map[element[1]] =
                (hash_map[element[1]] ? hash_map[element[1]] : 0) + 1)
    );
    return (
        Object.keys(hash_map).reduce((pre, value, idx, arr) => {
            return pre * (hash_map[value] + 1);
        }, 1) - 1
    );
}

function test() {
    for (let i = 0; i < 2; i++) {
        const result = solution(input.clothes[i]);

        if (result === input.answer[i]) {
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
