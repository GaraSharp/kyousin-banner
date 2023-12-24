# title : 凶シンモニター (準備中)
# begin : 2017-04-30 14:37:35 
# note  : 以前は tweet を wget して簡単に処理しておりましたが、
# note  : twitter が wget 出来ないので、今は、ランダムにwait　して、
# note  : バナー表示するだけのものとなっております

BEGIN {
    wait = 10 + rand()*10
    comm = "sleep " wait
    print comm
    system(comm)
    print "end"
}

