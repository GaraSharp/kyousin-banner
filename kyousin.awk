# title : 凶シンモニター
# begin : 2017-04-30 14:37:35 

BEGIN {

#  参照するTwitterページの指定。必要に応じてコメントアウトしたりして下さい
# 「地震速報」様 (@earthquake_jp)
  tweet = "https://twitter.com/earthquake_jp/with_replies"
#  「緊急地震速報Bot」様 (@eewbot) 
#  tweet = "https://twitter.com/eewbot/with_replies"

#  ダウンロード用一時ファイル
  tmp   = "/tmp/kyousin-monitor-temp-file"

  #  一旦、一時ファイルを削除しておきます
  system("rm -f " tmp)
  #  Twitterページをwgetでダウンロード
  system("wget -O " tmp " " tweet)

#  最初のtweetを取り出して、firstに保存しておきます
  flg = 1
  while (flg == 1) {
    flg = getline < tmp
    if ($0 ~ "js-tweet-text tweet-text") {
      first = substr($0, 110,  index($0, "</p>")-110)
      flg = 0
    }
  }
  close(tmp)	# closeして置くのが肝要
  printf "trig : %s\n", first

  #  新しいTweetを待ちます
  #  wait for new tweet
  new = first
  while (new == first) {
    system("sleep  10")
    system("rm " tmp)
    system("wget -O " tmp " " tweet)

    flg = 1
    while (flg == 1) {
      flg = getline < tmp
      if ($0 ~ "js-tweet-text tweet-text") {
        new = substr($0, 110,  index($0, "</p>")-110)
        flg = 0
      }
    }
    close(tmp)	# closeして置くのが肝要
    printf "new : %s\n", new

  }

  #  新しいTweetが入っていたら、ループを脱して
  printf "trig : %s\n", first
  #  バナー表示
  system("/opt/kyousin_banner/place-bitmap")

}

