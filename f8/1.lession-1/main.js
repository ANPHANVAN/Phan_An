
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

function getUserByComment(comments){
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      console.log("load comment sucsess")
      resolve(comments)
    }, 1000);
  })
}



function getNameByIds(ids) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let result = users.filter((user)=>{
        return ids.includes(user.id)
      })
      console.log(result)
      resolve(result)
    }, 2000);
  })
}


getUserByComment(comments)
  .then((cmt)=>{
    let getIds = cmt.map((callback)=>{
      return callback.user_id
    })
    console.log(getIds)
    
    return getNameByIds(getIds)
      .then((result)=>{
        return {users: result,
          comments: cmt}
      })
  })
  .then((data)=>{
    let getul = document.getElementById("list-comment")
    let htmls = '';
    data.comments.forEach(cmt => {
      var user = data.users.find(()=>{
        return users.id === cmt.user_id
      })
      htmls += `${user.name}: ${cmt.content}`
      console.log(htmls)
    });
    getul.innerHTML = htmls;
  })

