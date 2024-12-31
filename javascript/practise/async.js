async function getdata() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            resolve(404)

        }, 3000)
    })

}
console.log('Hay this is bhargav');

console.log("Devi")


async function main() {
    let data= await getdata()
    data.then(()=>{
    console.log('bhargav');
    })
    
}