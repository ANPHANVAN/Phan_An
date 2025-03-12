
let foods = [
  {
    id: 1,
    food: "Bugger",
    cooktime: 4000
  },
  {
    id: 2,
    food: "Sandwich",
    cooktime: 3000
  },  
  {
    id: 3,
    food: "Fried Chicken",
    cooktime: 8000
  }
]


function order (food, waittime) {
  console.log(`you order ${food} and you want wait less than ${waittime/1000}s`)
  return new Promise ((resolve, reject) => {

    //  take time food cook 
    let letTimeByFood = foods.find((value)=>{
      return value.food === food
    }).cooktime;
    console.log(`${food} must cook in ${letTimeByFood/1000}s`)

    if(waittime> letTimeByFood) {
      setTimeout(()=>{
        console.log(`this is your ${food} waiting in ${letTimeByFood}`)
        resolve();
      }, letTimeByFood);
    }
    else {
      console.log(`your order food have much time than your wating`)
      reject("error have a long time");
    }
  });
}


order("Bugger", 10000)
  .then(()=>{
    return console.log("finish or cancer the orders😎😋😋")
  })
  .then(()=> {
    return order("Fried Chicken", 10000)
  })
  .catch((error)=>{
    return console.log(error)
  })
  .finally(()=>{
    return console.log("finishor cancer the orders😎😋😋")
  })
  .then(()=> {
    return order("Sandwich", 2000)
  })
  .catch((error)=>{
    return console.log(error)
  })
  .finally(()=>{
    return console.log("finish or cancer the orders😎😋😋")
  })

