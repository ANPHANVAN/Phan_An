    let wait1 = new Promise((resolve) => {
        setTimeout(() => {
            // do task what and call back a resolve
            console.log("action settimeout in 2s")
            resolve(2)
        }, second(2));
    })

function second(second) {
    return second*1000;
}

    let wait2 = new Promise((resolve) => {
        setTimeout(() => {
            console.log("action setimeout in 3s")
            resolve(3)
        }, second(3));
    })

Promise.all([wait1, wait2])
    .then(([wait1, wait2])=>{
        console.log(wait1)
        console.log(wait2)
    });
