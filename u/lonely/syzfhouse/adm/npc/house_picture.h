//顯示屋宅圖樣

private int house_picture_user()
{
    message_vision("$n取出一份圖紙給$N看了一下，然後收了起來。\n",
                                    this_player(), this_object());
    tell_object(this_player(), "你看到圖紙上畫著：\n"HIW@PIC

　玲瓏屋   　隨意閣   　逍遙居  　　　錦繡宅
 ＝＝＝＝   ＝＝＝＝   ＝＝＝＝  ＝＝＝＝＝＝＝＝
‖　　　‖ ‖　　　‖ ‖　後院‖‖　　　後院　　‖
‖　　　‖ ‖　臥室‖ ‖◎　　‖‖　　◎　　　　‖
‖　臥室‖ ‖◎　　‖ ‖｜臥室‖‖　　｜臥室　　‖
‖◎　　‖ ‖｜客廳‖ ‖◎　　‖‖　　◎　　　　‖
‖｜　　‖ ‖◎　　‖ ‖｜客廳‖‖西廂｜廳 東廂 ‖
‖｜大門‖ ‖｜大門‖ ‖◎　　‖‖◎—◎—◎　　‖
‖△　　‖ ‖△　　‖ ‖｜大門‖‖　　｜　　　　‖
‖　　　‖ ‖　　　‖ ‖△　　‖‖　　△大門　　‖
 ＝＝＝＝   ＝＝＝＝   ＝＝＝＝  ＝＝＝＝＝＝＝＝

PIC NOR);
    return 1;
}

private int house_picture_bang()
{
    message_vision("$n取出一份圖紙給$N看了一下，然後收了起來。\n",
                                    this_player(), this_object());
    tell_object(this_player(), "你看到圖紙上畫著：\n"HIW@PIC

　　　 集賢會館　　　　　　　 聚英山莊
 ＝＝＝＝＝＝＝＝＝＝   ＝＝＝＝＝＝＝＝＝＝
‖　　　　　　　　　‖ ‖　　　　後院　　　‖
‖　　　　後院　　　‖ ‖　　　◎　　　　　‖
‖　　　◎　　　　　‖ ‖　西臥｜主臥　東臥‖
‖　　　｜臥室　　　‖ ‖◎——◎——◎　　‖
‖　　　◎　　　　　‖ ‖｜西廂｜中庭｜東廂‖
‖　議事｜客廳　講武‖ ‖◎——◎——◎　　‖
‖◎——◎——◎　　‖ ‖｜議事｜客廳｜講武‖
‖　　　｜武場　　　‖ ‖◎——◎——◎　　‖
‖　　　◎　　　　　‖ ‖　　　｜武場　　　‖
‖　　　｜大門　　　‖ ‖　　　◎　　　　　‖
‖　　　△　　　　　‖ ‖　　　｜大門　　　‖
‖　　　　　　　　　‖ ‖　　　△　　　　　‖
 ＝＝＝＝＝＝＝＝＝＝   ＝＝＝＝＝＝＝＝＝＝

PIC NOR);
    return 1;
}

private int house_picture_xian()
{
    message_vision("$n取出一份圖紙給$N看了一下，然後收了起來。\n",
                                    this_player(), this_object());
    tell_object(this_player(), "你看到圖紙上畫著：\n"HIW@PIC

　　　 廣陵逸境
 ＝＝＝＝＝＝＝＝＝＝
‖　　　　後院　　　‖
‖　　　◎┌二樓臥室‖
‖　琴房｜後廳　書齋‖
‖◎——●┴—◎　　‖
‖　　　｜花園　　　‖
‖　　　◎　　　　　‖
‖　西廂｜前廳　東廂‖
‖◎——◎——◎　　‖
‖　　　｜前院　　　‖
‖　　　◎　　　　　‖
‖　　　｜大門　　　‖
‖　　　△　　　　　‖
 ＝＝＝＝＝＝＝＝＝＝

PIC NOR);
    return 1;
}
