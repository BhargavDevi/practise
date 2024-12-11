console.log("hay bhargav");
console.log("how are you");


function myname(name) {
    console.log("hay "+name);

    console.log("how are you "+ name );
    
}
myname("bhargav")

function mean(n) {
    // console.log("Enter a number");
    return n*n*3.142;
}
console.log("The number is = "+mean(10));

let obj={
    name:"Bhargav",
    class:"E",
    branch:"ISE",

}
// using forin loop to print a number 
for (const key in obj) {
   {
        const element = obj[key];
        console.log(key+" ---> "+element)
    }
}

