



function color() {

    let v1 = 0 + Math.random() * 255;
    let v2 = 0 + Math.random() * 255;
    let v3 = 0 + Math.random() * 255;
    return `rgb(${v1} ${v2} ${v2})`


}

document.addEventListener("DOMContentLoaded", () => {

    let boxes = document.querySelectorAll(".box");
    boxes[2].style.backgroundColor = color();
    Array.from(boxes).forEach(e => {
        e.style.backgroundColor = color();
        e.style.color=color()
    });
});
