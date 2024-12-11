console.log("this a conditional statements");
let a='65';
// check both the value ant type
if(a===65){
    console.log("drive");
    
}
else{
    console.log("cant");   
}

let b=30,c=40;
e=b>c ?(b-c):c-b;
// translate   if(b>c){b-a}    else{c-b}
console.log(e);


// loops

console.log("tutorial on loop");
for (let index = 1; index <=20; index++) {
    console.log(index);
}
let obj={
    name:"bhargav",
    roll:"1si23is012"
}
// forin
for (const key in obj) {     {
        const element = obj[key];
        console.log(key ,element);
        
        
    }
}
// forof
for (const c of "bharagv") {
    console.log(c);
    
}
// i=0
// while (i<50) {
//     console.log(i);
    
//     i++;
// }
j=20
do {
    console.log(j)
    j++;
    
    
} while (j<2);