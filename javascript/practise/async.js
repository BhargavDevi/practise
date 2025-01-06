// async function getdata() {
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve(404)

//         }, 3000)
//     })

// }
// console.log('Hay this is bhargav');

// console.log("Devi")


// async function main() {
//     let data= await getdata()
//     data.then(()=>{
//     console.log('bhargav');
//     })
    
// }

// async function getdata() {
//     return new Promise((resolve,reject)=>{
//         setTimeout(()=>{
//             resolve(455);
//         },3000)
//     })
// }
async function getdata() {
    let y=await fetch('https://jsonplaceholder.typicode.com/todos/1')
      let data=await y.json()
      console.log(data);
      
}

async function main() {
    console.log('helo this us bhargav');
    let data = await getdata();
    console.log(data);
    
    //  data.then((v)=>{
    //     console.log("Hii")
    // })
    
    console.log('i am here ');

}
main()
