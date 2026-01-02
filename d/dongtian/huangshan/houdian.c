// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

#define YXNUM 3500

string look_xiang(object me) {
    object ring, ob;

    if (me->is_busy()) return NOR BUSY_MESSAGE NOR;
    me->start_busy(2);

    ring = find_object(__DIR__"ring");
    if (! ring) ring = load_object(__DIR__"ring");
    if (ring) {
        if (objectp(ob = environment(ring)) ) {
            return NOR + HIK "長明燈上刻著一個名字『" + HIY + query("name", ob) + NOR + HIK + "』\n" + NOR + "( 你尋思著要不要<pick>... )\n" + NOR;
        }
    }
    return NOR + HIK "長明燈上有朵美輪美奐的" + HIY + "火焰蓮花" + NOR + HIK + "正跳躍燃燒著。\n" + NOR + "( 你尋思著要不要<pick>... )\n" + NOR;
}

int do_pick() {
    object me = this_player();
    object ring, ob;

    if (me->is_busy()) {
        write(NOR BUSY_MESSAGE NOR);
        return 1;
    }
    me->start_busy(3 + random(2));

    if (query("pick_time") && query("pick_time") > time()) {
        write(NOR "長明燈上的蓮花十分鐘內才被人掐過。\n" NOR);
        return 1;
    }

    set("pick_time", time() + 600);
    ring = find_object(__DIR__"ring");
    if (! ring) ring = load_object(__DIR__"ring");
    if (ring) {
        ring->reborn();
        if (objectp(ob = environment(ring)) && playerp(ob) ) {
            message_vision(NOR + HIC + query("dtname", ring) + "洞天" + NOR + YEL + "傳來半聲清鳴，$N" +
                NOR + YEL + "身上的" + query("name", ring) + NOR + YEL + "滴溜溜一轉，旋即化作星芒循聲而去...\n" + NOR, ob);
        }
        message_vision(NOR + HIY + "火焰蓮花" + NOR + CYN + "沿著$N" + NOR + CYN + "食指倏地燒上手掌，$N" + NOR + CYN + "趕忙抓住定睛一看，卻是支古樸的髮簪。\n" + NOR, me);
        ring->move(me);
    }
    return 1;
}

void create() {
    set("short", __DIR__"guangchang.c"->load_name() + "後殿");
    set("long",
        "走過大殿，穿過幽靜的小路，便來到後殿，與大殿的熱鬧比起來，這裡\n"
        "確實冷清之極。只見偌大的一片空地上，矗立著一座氣勢非凡的殿堂，四角\n"
        "飛簷，琉璃瓦頂，古香古色的門牌紅柱，彷彿都在這一片寧靜中訴說著昔日\n"
        "的歷史。一陣陣青煙，從深邃而顯得有些陰暗的殿內飄出，從外面看，只見\n"
        "裡面燭火點點，更有長明燈("CYN"deng"NOR")微微搖晃，懸掛半空。\n"
    );
    //set("outdoors", "yangzhou");
    set("exits",([ /* sizeof() == 1 */
        "south": __DIR__"dadian",
        "north": __DIR__"yaopu"
        ]));

    set("item_desc", ([
        "長明燈": (: look_xiang :),
        "燈": (: look_xiang :),
        "deng": (: look_xiang :)
        ]) );

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);    //睡覺不雅觀
    set("no_kill", 1);
    //set("no_fight",1);

    set("owner_level", 2);
    set("max_carry_user" , 1);
    set("dongtianfudi", YXNUM);

    setup();
}

int clean_up() { return 1;}

int discmdkill() {
    tell_object(this_player(), "你不能在這裡毛手毛腳。\n");
    return -1;
}

void init() {
    add_action("discmdkill", "kill");
    add_action("do_pick", "pick");
    set("max_carry_user", 1 + query("zhen_type", get_object(__DIR__"guangchang")));
    set("dongtianfudi", YXNUM + query("apply/num_yanxi", get_object(__DIR__"guangchang")));
    ::init();
}
