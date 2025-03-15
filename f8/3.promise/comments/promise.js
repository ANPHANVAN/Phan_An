// create a function display comment
function getComments() {
  let comments = [
    { id: 1, user_id: 101, content: "This is an amazing post!" },
    { id: 2, user_id: 102, content: "I totally agree with this." },
    { id: 3, user_id: 103, content: "Great insights, thanks for sharing!" },
    { id: 4, user_id: 101, content: "I have a different perspective on this." },
    { id: 5, user_id: 104, content: "Can you provide more details?" }
  ];
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(comments)
    }, 1000);
  })
}

function getNames(arr) {
  let users = [
    { id: 101, name: "Alice" },
    { id: 102, name: "Bob" },
    { id: 103, name: "Charlie" },
    { id: 104, name: "David" },
    { id: 105, name: "Emma" }
  ];
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      let filterUser = users.filter((user)=>{
        return arr.includes(user.id)
      })
      resolve(filterUser)
    }, 1000);
  })
}



//  action
getComments()
  .then((comments)=>{
    let commentIds = comments.map((comment)=>{
      return comment.user_id
    })
    return getNames(commentIds)
    .then((users)=>{return {users:users, comments: comments}})
    })
  .then((data) => {
    let getul = document.getElementById("list-ul");
    let html = "";
  
    data.comments.forEach(comment => {
      let user = data.users.find(user => Number(user.id) === Number(comment.user_id));
  
      if (user) {
        html += `<li>${user.name}: ${comment.content}</li>`;
      } else {
        console.warn("Không tìm thấy user cho comment:", comment);
      }
    });
  
    getul.innerHTML = html;
  });


  //  Gọi API ngoài
  // get API realtime
function getAPI(){
  fetch('https://jsonplaceholder.typicode.com/posts/1')
    .then(response =>response.json())
    .then(json => title = json)
}
let title = null;
getAPI()

setTimeout(() => {
  console.log("Dữ liệu sau 2s:", title);
}, 2000);
  


