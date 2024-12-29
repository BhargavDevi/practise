// console.log("i am bhargav");

// setTimeout( () => {
//     console.log("gangster");
// },2000);
// console.log("End");

// function callback(arg) {
//     console.log(arg);
    
//     // callback
// }
// function lodescript(src,callback) {
//     const sc=document.createElement("script")
//     sc.src=src;
//     sc.onload=()=>callback("Bhargav");
//     document.head.append(sc);

    
// }


// lodescript("https://cdnjs.cloudflare.com/ajax/libs/prism/9000.0.1/prism.min.js", callback );

// promiss


console.log('this is a promiss');

const prom1=new Promise((resolve,reject)=>{
    let a=Math.random();
    if (a<0.5) {
        reject("Error");
        
    }
    
    else{
        
        setTimeout(()=>{
             console.log('I am done ');
             resolve("Bhargav")
        },0);
    }
})

const prom2=new Promise((resolve,reject)=>{
    let a=Math.random();
    if (a<0.5) {
        reject("Error 2");
        
    }
    
    else{
        
        setTimeout(()=>{
             console.log('I am done 2');
             resolve("Bhargav 2")
        },0);
    }
})
// prom1.then((e)=>{
//     console.log(e);
    
// }).catch((err)=>{
//     console.log(err);
    
// })
let p3=Promise.race([prom1,prom2])
p3.then((a)=>{
    console.log(a);
    
}).catch((err)=>{
    console.log(err);
    
})