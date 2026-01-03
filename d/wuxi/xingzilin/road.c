// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <room.h>
#include <ansi.h>
inherit ROOM;

int clean_up() { return 1;}

string look_pai(object me);

void create() {
    set("short", "杏林小道");
    set("long",
        "這是一條黃土小路，兩旁的杏樹薄霧飄繞。遙望東面又是一片茂密\n"
        "的杏樹林，隱約有人馬的聲音傳來。路邊的樹上掛著一個"+CYN + "牌子"+NOR + "。\n"
    );
    set("no_sleep_room", 1);
    set("no_magic", 1);
    set("no_clean_up", 1);
    set("channel_id", "掛級精靈");
    set("msg_hero", "無");
    set("exits", ([
        "east": __DIR__"road2",
        "west": "/d/wuxi/xinlin1"
        ]));
    set("objects", ([
        "/clone/npc/walker"  : 1
        ]));
    set("item_desc", ([
        "牌子": (: look_pai :),
        "pai": (: look_pai :),
        "paizi": (: look_pai :)
        ]) );

    setup();
    call_out("put_eren", 1800);
}

void init() {
    if (playerp(this_player()))
    {
        if (!query("dynaroom_ok"))
        {
            set("dynaroom_ok", 1, this_object());
            load_object(__DIR__"dynaxzl.c")->create();
        }
        delete_temp("xzz", this_player());  //連悲酥清風一起清除
    }
}

int valid_leave(object me, string dir) {
    if (dir == "east" && ! playerp(me)) return 0;   //阻擋npc進入區域
    if (dir == "east") {
        set_temp("xzz/ntrip", 0, me);   //移動懲罰和殺怪數清0
        set_temp("xzz/nkill", 0, me);
        set_temp("xzz/ntrip2", 0, me);
        set_temp("xzz/nkill2", 0, me);
        set_temp("xzz/kar", 15 + random(19), me);
        set_temp("xzz/entertime", time(), me);
    }
    return ::valid_leave(me, dir);
}


mixed put_eren()    //放置惡人
{
    string str;
    object ob, eren, where, *ulist;
    int count;
    count = 0;
    ulist = users();
    str = "";
    //              str = HIY + "玩家位置:\n";
    foreach (ob in ulist)
    {
        where = environment(ob);
        if (!where) continue;
        //              if (where) str += NOR+"  "+ query("name", ob) + " = "+HIC+ query("short", where) + ((query("ngroup", where)==2) ? HIY+ " <-目標！" : "") + "\n" + NOR;
        if (query("ngroup", where) && !query_temp("xzz/kar", ob)) set_temp("xzz/kar", 15 + random(19), ob);     //防止意外出現在林子裡的玩家出現異常
        if (query("ngroup", where)==2)
        {
            if (random(100) <= (query_temp("xzz/kar", ob))) {
                message_vision(YEL "樹林中突然傳來幾聲陰笑，一個黑影縱身往$N撲去。\n" NOR, ob);
                eren = new(__DIR__"npc/eren");
                eren->move(where);
                eren->set_leader(ob);
                count += 1;
                //如果刷怪數保持大於1000再次獲得惡人的機會！這也可能是危險，所以要求站著的人手動走走去找boss
                if ((query_temp("xzz/nkill2", ob))>=1000 && random(100) <= (query_temp("xzz/kar", ob)))
                {
                    message_vision(YEL "樹林中突然又傳來幾聲陰笑，一個黑影縱身往$N撲去。\n" NOR, ob);
                    eren = new(__DIR__"npc/eren");
                    eren->move(where);
                    eren->set_leader(ob);
                    count += 1;
                }
            }
        }
        if (sscanf(base_name(where), "/d/wuxi/xingzilin/%*s") && query_temp("xzz/entertime", ob)) str += "  " + HIC + query("family/family_name", ob) + query("family/title", ob) + " " + RED + query("name", ob) + NOR + "(" + query("id", ob) + ")  - " + ctime(query_temp("xzz/entertime", ob) ) + "\n";
    }
    //              write  (str);
    if (str == "") str = "無";
    set("msg_hero", str);
    CHANNEL_D->do_channel(this_object(), "sys", "杏子林掛級點深處投放了"+ count + "個四大惡人。\n");
    call_out("put_eren", 1200 + random(900));   //隨機是為了避免有機器人準時進去投機
    return 1;
}



string look_pai(object me) {
    return
    HIY + "rideto wuxi,e,e,e,n,e,l pai\n" + NOR +
        HIG + "《杏子林》示意：\n" + HIC +
        "※※※※※※※※※※※※※※\n" +
        "※              □□□□□※\n" +
        "※              □□□□□※\n" +
        "※      (深處)  □□□□□※\n" +
        "※              □□□□□※\n" +
        "※              □□□□□※\n" +
        "※                  ↑    ※\n" +
        "※                □□□  ※\n" +
        "           (外圍) □□□  ※\n" +
        "                  □□□  ※\n" +
        "【無錫城東】        ↑    ※\n" +
        "杏林→□□□□□□□□    ※\n" +
        "                          ※\n" +
        "※※※※※※※※※※※※※※\n" +
        "\n" + NOR +
        HIG + " - 官府公告：\n" + NOR +
        "1)杏林到杏子林外圍的小路上，小心西夏武士的埋伏，20lv以下的玩家切勿犯險\n" +
        "2)杏子林外圍為固定大小，刷新六七八品武士\n" +
        "3)杏子林深處為不定大小，刷新二三四五品武士和一品高手四大惡人\n" +
        "4)外圍和深處之間的岔道上，有一安全房間，其中有個丐幫長老可做任務\n" +
        "5)杏子林遍佈著悲酥清風和陷阱，"+HIR + "切忌橫衝直闖"+NOR + "，用“maphere”查看地圖\n" +
        "6)努爾海在杏子林外圍，隱秘潛伏著極難出現，最好先大量擊殺他手下的武士再行尋找\n" +
        "7)赫連鐵樹在杏子林深處出沒，其餘同上\n" +
        ((query("msg_hero")=="無") ? "" : "\n\n" + HIG + "      《中原英雄立志榜》"+NOR + RED + "手印：\n" + query("msg_hero") + "\n" + NOR)
    ;
}
