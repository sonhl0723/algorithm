var N;

const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });

function main(N){
    const ROW = 10;
    const COLUMN = 2;
    const arr = new Array(ROW);

    for (var i = 0; i < ROW; i++) { arr[i] = new Array(COLUMN); }
    for (var i = 0; i < ROW; i++) {
        if(i==0) arr[i][1]=0;
        else arr[i][1]=1;
        if(i==0) arr[i][0]=0;
        else arr[i][0]=1;
    }

    var result = 0;

    while(N>1){
        for (var i=0; i<ROW; i++){
            arr[i][0] = 0;
        }
        for (var i=0; i<ROW; i++){
            if(i==0) arr[1][0]=((arr[1][0]+arr[i][1])%1000000000);
            else if(i==9) arr[8][0]=((arr[8][0]+arr[i][1])%1000000000);
            else{
                arr[i-1][0]=((arr[i-1][0]+arr[i][1])%1000000000);
                arr[i+1][0]=((arr[i+1][0]+arr[i][1])%1000000000);
            }
        }
        for (var i=0; i<ROW; i++){
            arr[i][1] = arr[i][0];
        }
        N-=1;
    }

    for (var i=0; i<ROW; i++) result=((result+arr[i][0])%1000000000);

    return result;
}

// console.log(main(N));

readline.question('', N => {
    // console.log(`${N}!`);
    console.log(main(N));
    readline.close();
});