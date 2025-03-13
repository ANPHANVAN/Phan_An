//  forEach
Array.prototype.forEach2 = function(cb) {
    for(let element = 0 ; element < this.length; element++ ) {
        if (this.hasOwnProperty(element)){
            cb(this[element],element, this)
        }
    }
}

// map
Array.prototype.map2 = function (fun){
    len = this.length;
    let arr = [];
    for (let index =0; index < len ; index ++) {
        arr.push(fun(this[index], index, this))
    }
    return arr
}

// every
Array.prototype.every2 = function (fun){
    let result = true
    len = this.length;
    for (let index =0; index < len ; index ++) {
        if (fun(this[index], index, this)) {
            result = true;
        }
        else {
            result = false;
            break;
        }
    }
    return result
}

// every
Array.prototype.some2 = function (fun){
    let result = true
    len = this.length;
    for (let index =0; index < len ; index ++) {
        if (!fun(this[index], index, this)) {
            result = false;
        }
        else {
            result = true;
            break;
        }
    }
    return result
}

// find

Array.prototype.find2 = function (callback){
    let len = this.length;
    for (let index = 0; index < len; index++) {
        if (callback(this[index], index, this)) {
            return this[index]
        }
    }
}

// filter
Array.prototype.filter2 = function (callback){
    let len = this.length;
    let arr = [];
    for (let index = 0; index < len; index++) {
        if (callback(this[index], index, this)) {
            arr.push(this[index])
        }
    }
    return arr;
}

// reduce
Array.prototype.reduce2 = function (callback, caculator=0){
    let len = this.length;
    for (let index = 0; index < len; index++) {
        caculator = callback(caculator, this[index], index, this)
    }
    return caculator
}


const numbers = [1, 2, 3, 4, 2];


numbers.forEach((element, elementIndex)=>{
    console.log(element, elementIndex)
})

numbers.forEach2((element, elementIndex)=>{
    console.log(element, elementIndex)
})


console.log(numbers.map2((val) => {return val * 2})); // [2, 4, 6, 8, 10]

console.log(numbers.reduce((caculate,element, index)=>caculate * element , 30))
console.log(numbers.reduce2((caculate,element, index)=>caculate * element, 30))


// forEach2: In ra từng phần tử
numbers.forEach2((val, i) => console.log(`Index ${i}: ${val}`));

// map2: Nhân đôi mỗi phần tử
console.log(numbers.map2((val) => val * 2)); // [2, 4, 6, 8, 10]

// every2: Kiểm tra tất cả đều lớn hơn 0?
console.log(numbers.every2((val) => val > 0)); // true

// find2: Tìm số lớn hơn 3
console.log(numbers.find2((val) => val > 3)); // 4

// filter2: Lọc số chẵn
console.log(numbers.filter2((val) => val % 2 === 0)); // [2, 4]