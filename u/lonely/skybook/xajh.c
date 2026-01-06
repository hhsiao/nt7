// This program is a part of NT MudLIB
// 笑傲江湖

#include <ansi.h>

#define DEBOOKS "笑傲江湖"

// 序章開始時調用的劇情簡介
string *BookMsg = ({
    "其時武林之中，既有正邪之判，復存門戶之別，少林、武當、青城、五嶽自詡正教與魔教（日月神教）冤冤相報，誓不兩立。",
    "五嶽劍派名雖一體，實存芥蒂。嵩山掌門左冷禪野心勃勃，意欲吞併五嶽，稱霸江湖，自恃盟主身份，凌駕四嶽掌門，挑撥華山劍宗爭奪掌門之位。",
    "岳不群原屬氣宗，劍、氣二宗素不相和，不群率本門弟子外出避禍，遭左道之士埋伏，俱被擒獲。",
    "江湖之中流傳著一個傳說，林家祖傳的《辟邪劍法》乃天下無敵之武功，誰能練成將天下無敵！",
    "福建林遠圖以七十二路辟邪劍法稱雄武林，創立福威鏢局，笑傲江湖，馳騁天下。",
    "遠圖死後，子孫無能，四方豪傑覬覦辟邪劍譜，紛至沓來 ……",
    "辟邪劍譜之爭，武林盟主之爭，由此拉開序幕！"
});

mapping book_list = ([

    "1": ([ "當前章節" : "第一章",
        "當前任務" : "路見不平",
        "任務描述" : "青城派弟子欺辱一個文弱公子，你路見不平，拔刀相助。",
        "loadboss": "qcdz.data",    // 建立副本，生成boss,進入副本戰鬥

//"任務狀態" : 0,
//"任務編號" : "1",

        "下個任務" : "5", ]),
    "5": ([ "當前章節" : "第一章",
        "當前任務" : "青城四少",
        "任務描述" : "青城派弟子帶來了幫手，傳說中的青城四少，看樣子你不得不動武了。",
        "下個任務" : "10", ])
    ]);

mapping query_book_list(string n) {
    if(undefinedp(book_list[n]) ) return 0;
    return book_list[n];
}

// 來自 /cmds/usr/skybook.c調用，開始天書任務
void startbook(object me, string sBook) {
    string sQuest;  // 當前任務編號
    string sZhangjie;   // 當前章節

    sZhangjie = me->query("skybook14/" + sBook + "/當前章節");
    sQuest = me->query("skybook14/" + sBook + "/任務編號");     // 表示還沒有完成的任務編號


    if (sQuest == "1")
    {
        DIALOG_D->start_dialog4(this_object(), me, sBookMsg, 0, 1);
        return;
    }


    FUBEN_D->move_all_invalid_user(me);

    move_to_room(me, sQuest);

    return;

}

// 副本全部通關，大結局
void endskybook(object me) {

    // 通知玩家完成了該天書
    tell_object(me, BLINK + HIY "\n恭喜你！成功通關《" + DEBOOKS + "》天書！\n\n" NOR);

    // 廣播全服
    CHANNEL_D->do_channel(this_object(), "rumor", "聽說" + HIY + me->query("name") + "(" + me->query("id") + ")" HIM "闖關《" + DEBOOKS + "》天書成功！\n");

    log_file("通關天書", me->query("id") + " at " + ctime(time()) + " 通關 " + DEBOOKS + "\n" );

    // 累積該完成次數
    me->add("skybook14/option/" + DEBOOKS + "/completed_times", 1);

    // 給予通關固定獎勵
    GIFT_D->delay_bonus(me,
        ([
            "exp": 5000000,
            "pot": 5000000,
            "mar": 5000000,
            "prompt": "你在通關《" +  DEBOOKS + "》天書後" ]), 999);

    // 給予通關隨機獎勵
    SUICONG_D->give_end_gift(me, DEBOOKS, me->query("skybook14/" + DEBOOKS + "/難度"));

    return;

}
