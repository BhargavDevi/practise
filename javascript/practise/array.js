// console.log("array");

// let a=[1,2,3,4]
// console.log(a);
// console.log(a.length);
// console.log(a[0]);
// // indexing
// a[0]=222
// console.log(a);
// console.log(typeof(a));
// // array to a string
// console.log(a.toString());
// console.log(a.join(" and "  ));
// console.log(a.pop());


// console.log(a.push('bharagv'));
// console.log(a);


// let a=[1,2,3,3,4]
// for (let index = 0; index < a.length; index++) {
//     const element = a[index];
//     console.log(a[index]);
// }

array=[2,3,12,33,]
array.forEach((value,index,array )=> {
    console.log(value,index,array);
    
});

for (const element of array) {
    console.log(element);
    
}

let aaa=[1,22,32,2]
let newon=[]
for (let i  = 0; i  < aaa .length; i ++) {
    const element = aaa [i ];
    newon.push(element*element)
    
}console.log(newon);



let neww=aaa.map((e)=>{
    return e**e;
})
console.log(neww);

let greaterthanfive=(e)=>{
    if(e>5){
        return true;
    }
    else{
        return false;
    }
}

console.log(aaa.filter(greaterthanfive));
// return the filtered element
let oo=[]
let obj={
    name:"Bhar ",
    usn:"1si32"
}
// console.log(Object.value(obj));
let ob="Bhargav"

console.log(Array.from(ob));
