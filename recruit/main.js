"use strict";
const uri = "https://challenge-server.code-check.io/api/kidnapper";

function main(argv) {
  const token = argv[0];
  let num = argv[1];
  start(token, argv[1]);
}

function start(token, num){
  num = num - 1;
  // XMLHttpRequestオブジェクトの作成
  let url = uri + "/start?token=" + token;
  let request = new XMLHttpRequest();
  request.open('GET', url, true);

  // レスポンスが返ってきた時の処理を記述 
  request.onload = function () {
    let data = this.response;
    let to = data["goto"];
    deliver(token, num, to);
  }

  // リクエストをURLに送信
  request.send();
}

function deliver(token, num, to){
  num = num - 1;
  // XMLHttpRequestオブジェクトの作成
  let url = uri + "/deliver?token=" + token + "&to=" + to;
  let request = new XMLHttpRequest();

  request.open('GET', url, true);

  // レスポンスが返ってきた時の処理を記述 
  request.onload = function () {
    let data = this.response;
    if(num > 0){
      to = data["goto"];
      deliver(token, num, to);
    }else{
      console.log(to);
    }
  }

  // リクエストをURLに送信
  request.send();
}

main(process.argv.slice(2));//第一引数をtoken, 第二引数を回数としてmain関数を実行