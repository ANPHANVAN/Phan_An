
let comments = [
  {
    id: 1,
    user_id: 1,
    content: "you are handsome",
  },
  {
    id: 2,
    user_id: 2,
    content: "you are urly",
  },  
  {
    id: 1,
    user_id: 1,
    content: "you are beautyful",
  }
]

let users = [
  {
    id:1,
    name: "Phan An"
  },
  {
    id:2,
    name: "Phan Binh"
  },
  {
    id:3,
    name: "Phan Tinh"
  },
  {
    id:4,
    name: "Phan Nhan"
  },
]


function setTime(ms) {
  return new Promise((resolve, reject) => {  // ✅ Đặt Promise bọc toàn bộ logic
    if (ms < 5000 && ms >= 0) {
      setTimeout(() => {
        console.log(`run task in ${ms}`)
        resolve(ms);  // ✅ Đúng: resolve được gọi bên trong Promise
      }, ms);
    } else {
      reject("have so much time to run > 5s");  // ✅ Đúng: reject được gọi bên trong Promise
    }
  });
}


console.log(setTime(1000)
  .then(function (rs) {
    console.log(`1 in plus ${rs}`);
    return setTime(rs+1000);
  })
  .then(function(rs){
    console.log(`2 in plus ${rs}`)
    return setTime(rs+1000);
  })
  .then(function(rs){
    console.log(`3 in plus ${rs}`)
    return setTime(rs+1000);
  })
  .then(function(rs){
    console.log(`4 in plus ${rs}`)
    return setTime(rs+1000);
  })
  .catch((rs)=>{
    return console.log(`Have error: ${rs}`)
  })
)