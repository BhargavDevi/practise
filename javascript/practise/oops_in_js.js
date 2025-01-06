// class myclass {
//     constructor(parameters) {
        
//     }
// // }

// let obj={
//     1:'aa',
//     2:"sasd"
// }
// console.log(obj);
// let animal={
//     eats:true,
//     walks:true,
//     flyes:'no they dont '
// };
// let man={
//     jump:true
// }; 
// man.__proto__=animal;
// // __proto__ is an additional properties in js.   which can be used



class anima {
    constructor() {
        console.log('object is been created....');
        
    }
    eat(){
        console.log('they eat');
    }
    fly(){
        console.log('"They fly as well');
        
    }
}


let r=new anima();
console.log(r);
