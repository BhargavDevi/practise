console.log('hello');

async function get() {
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve(455);
        },3000)
    })
}
async function main() {
    
    console.log('bhargav');
    let s=await get();
    alert("lode is completed")
    console.log(s)
}
main()