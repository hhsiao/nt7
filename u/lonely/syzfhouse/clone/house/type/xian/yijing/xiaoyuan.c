// xiaoyuan.c

#include <ansi.h>
inherit "/inherit/room/house_door";

void create()
{
    set("short", "仙宅大門");
    set("long", @LONG
眼前好大一片宅院，但見樓臺瑰麗，玉牆蜿蜒，不知佔地有多少畝。
周遭雲霧飄渺繚繞，景緻似真似幻，令人如在夢中。
LONG);

    set("exits",
    ([
        "out"   : __FILE__,
        "north" : __DIR__"qianyuan",
    ]));

    set("owner_name", "某人");
    set("owner", "OWNER");
    set("huyuan", __DIR__"huyuan");
    set("outdoors", "OUTDOORS");
    set("forbid_exits", "north");
    set("max_laodu", 1000000);
    set("now_laodu", 1000000);

    setup();
    restore();
}

int valid_leave(object me, string dir)
{
    if(dir != query("forbid_exits"))
        return ::valid_leave(me, dir);

    if(!wizardp(me)
        && me->query("id") != query("owner")
        && me->query("couple/couple_id") != query("owner")
        && !me->query_temp("invited_guest/" + query("owner")))
            return notify_fail(WHT "前面似乎有一陣無形的真氣擋住，"
                                   "令你再也無法前行半分。\n" NOR);

    message_vision(HIC "\n一片雲霧飄來，輕輕將$N裹起，"
                       "飄飄悠悠地飛了進去。\n" NOR, me);
    return ::valid_leave(me, dir);
}
