// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

#define YXNUM 3000

void create() {
    set("short", __DIR__"guangchang.c"->load_name() + "大殿");
    set("long",
        "走過前庭，正前方便是大殿所在，青山含翠，殿宇雄闊，大殿坐落峰頂\n"
        "雲氣繚繞，時有仙鶴幾隻，長鳴飛過，在空中盤旋不去，如仙家靈境，令人\n"
        "心生敬仰。順橋繼續前行，此時虹橋不再上升，在空中做個拱形，落在殿前\n"
        "一灣碧水寒譚邊。於此同時，大殿裡隱隱傳出仙樂歌訣，一派仙家氣勢。潭\n"
        "水邊，一條寬敞石階，從水潭邊向上直通殿門。潭水碧清，如鏡，人影山影\n"
        "清晰可見。走過高高石階，遠遠便看到大殿門扉大開，裡面光線充足，供奉\n"
        "著盤古，女媧之神位，氣度莊嚴。神位之前，大殿之上。站著數十餘人，有\n"
        "道有俗，看來都是門徒，個個神光內斂，面目和善，看來都是有道的修行者。\n"
    );
    //set("outdoors", "yangzhou");
    set("exits",([ /* sizeof() == 1 */
    "south": __DIR__"qianting",
        "north": __DIR__"houdian"
    ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);    //睡覺不雅觀
    set("no_kill", 1);
    //set("no_fight",1);

    set("owner_level", 1);
    set("max_carry_user" , 6);
    set("dongtianfudi", YXNUM);

    setup();
}

int discmdkill() {
    tell_object(this_player(), "你不能在這裡毛手毛腳。\n");
    return -1;
}

void init() {
    object ob, me = this_player();
    if (playerp(me) && wiz_level(me) < 6) me->start_busy(2);
    if (query_temp("dongtian/user_cant_die", me)) {
        delete_temp("dongtian/user_cant_die", me);
        me->start_busy(60);     //失敗復活的代價
    }
    if ((playerp(me)||me->is_baby()) && !query_temp("dongtian/invite/armor", me)) {
        ob = new(__DIR__"armor");
        ob->reborn(me);
        if (ob->move(me)) {
            set_temp("dongtian/invite/armor", ob, me);
            tell_object(me, NOR YEL "金光一閃，傀儡侍衛撲向你身上...\n" NOR);
        } else {
            destruct(ob);
        }
    } else if (playerp(me) && objectp(ob = query_temp("dongtian/invite/armor", me)) ) {
        ob->fill();
        if(!query("consistence", ob) || query("consistence", ob) < 100 ) {
            set("consistence", 100, ob);
            tell_object(me, NOR CYN "靈氣洶湧，你身上的洞天甲煥然一新。\n" NOR);
        }
    }
    if ((playerp(me)||me->is_baby()) && (query("dongtian/invite_item/charm_time", me)!=time() / 86400)) {
        set("dongtian/invite_item/charm_time", time() / 86400, me);
        ob = new(__DIR__"charm");
        ob->reborn(me);
        if (ob->move(me)) {
            tell_object(me, NOR CYN "你聽到飄渺的聲音說道：賜下今日的氣運符在身，\n  它對你在洞天內各場所的行動大有益處，趕快抓緊時間利用好吧。\n" NOR);
            me->command("wear qiyun fu");
        } else {
            destruct(ob);
        }
    }
    add_action("discmdkill", "kill");
    set("max_carry_user", 6 + 2 * query("zhen_type", get_object(__DIR__"guangchang")));
    set("dongtianfudi", YXNUM + query("apply/num_yanxi", get_object(__DIR__"guangchang")));
    ::init();
}
