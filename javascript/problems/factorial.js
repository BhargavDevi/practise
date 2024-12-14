
// using recursion

let fact=e=>{

    if(e==0||e==1){
        return 1;
    }
    let c= e*(fact(e-1));
    return c;
}
console.log(fact(7));



// by only osing reduse fun and for loop
let a=[];
let n=7
for (let index = n; index !=0; index--) {
    // const element = array[index];
    a.push(index);
}
console.log(a);
let mul =(a,b)=>{
    return a*b
}
console.log(a.reduce(mul));
