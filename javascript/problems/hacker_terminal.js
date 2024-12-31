async function hacker() {
    function htm1() {
        return new Promise((resolve) => {
            setTimeout(() => {
                document.getElementById("m1").innerHTML = 'Initializing Hacking...';
                resolve();
            }, 0);
        });
    }

    function htm2() {
        return new Promise((resolve) => {
            setTimeout(() => {
                document.getElementById("m2").innerHTML = 'Reading your Files...';
                resolve();
            }, 2000);
        });
    }

    function htm3() {
        return new Promise((resolve) => {
            setTimeout(() => {
                document.getElementById("m3").innerHTML = 'Password files Detected...';
                resolve();
            }, 4000);
        });
    }

    function htm4() {
        return new Promise((resolve) => {
            setTimeout(() => {
                document.getElementById("m4").innerHTML = 'Sending all passwords and personal files to server...';
                resolve();
            }, 6000);
        });
    }

    function htm5() {
        return new Promise((resolve) => {
            setTimeout(() => {
                document.getElementById("m5").innerHTML = 'Cleaning up...';
                resolve();
            }, 4000);
        });
    }

    await htm1();
    await htm2();
    await htm3();
    await htm4();
    await htm5();
}

async function main() {
    await hacker();
}

main();
