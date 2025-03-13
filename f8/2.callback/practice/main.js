// console.log(flatten([1, [2, [3, 4]], 5])) // 👉 [1, 2, 3, 4, 5]
// console.log(flatten([[["a"]], [["b"]]])) // 👉 ["a", "b"]

let arr = [1, [2, [3, 4,[4,9,7,[5,7]]]], 5]
let arr2 = [[["a"]], [["b"]]]

console.log(flatten(arr))

function flatten(arr) {
    let result = [];
    arr.forEach(element => {
        if (Array.isArray(element)) {
            result.push(...flatten(element)); // Trải rộng phần tử nếu là mảng
        } else {
            result.push(element);
        }
    });
    return result;
}