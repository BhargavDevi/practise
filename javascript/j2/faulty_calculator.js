let a=prompt("Enter a number");
let b=prompt("Enter a number");
let c=prompt("Enter the operation need to be performed");
console.log(a+" "+b);

function getRndInteger(min, max) {
    return Math.floor(Math.random() * (max - min)) + min;
  }

// console.log(getRndInteger(1,100));
let d=getRndInteger(1,100);
// console.log(d);

// let obj={
//     '+':'-',
//     '*':'+',
//     '-':'/',
//     '/':'**'
// }
// for (const key in obj) {
//      {
//         const element = obj[key];
//         if(c=key){
//             console.log(a element b);
//             break;
//         }
//     }
// }

if(d<=10){
    switch (c) {
        case '+':
            console.log(a-b);
            break;
        case '*':
            let e=a+b;
            console.log(e);
            break;
        case '-':
            console.log(a/b);
            break;
        case '/':
            console.log(a**b);
            break;
    
        default:
            console.log("invalid choise");
            
            
    }
}
else{
    switch (c) {
        case '+':
            let e=a+b;
            console.log(e);
            break;
        case '*':
            console.log(a*b);
            break;
        case '-':
            console.log(a-b);
            break;
        case '/':
            console.log(a/b);
            break;
    
        default:
            console.log("invalid choise");
            
            
    }
}