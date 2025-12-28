#include <ansi.h>
#include <room.h>

inherit PRIVATE_ROOM;

void create()
{
        set("short", "化樂天柱峰");
        set ("long", 
" "HIY"☆" NOR "\n"
"    　"HIY"★"NOR"　　"HIY"☆"NOR"　"MAG"夢迴巫山雨悠悠·再蹈滄海盡綢繆" NOR "\n"
"    　　　　　　　　　　　　　"CYN"≈≈"NOR"　　"HIY"★"NOR"　　" NOR "\n"
"    　　"CYN"≈"NOR"　　/○\\ ●　　　 "CYN"≈ ≈≈"NOR"　　　" NOR "\n"
"    　"CYN"≈≈≈"NOR"　/■\\/■\\　　"CYN"≈≈≈≈≈≈"NOR"　　" NOR "\n"
"    ╪═╪═╪ <|　||　══╪═╪═╪═╪　" NOR "\n"
"    ------------------------------         " NOR "\n"
"    這裡能遙遙眺望到遠處的碧海，寧謐的雲霧如龍蛇在四下游動。" NOR "\n"
);

        setup();

        set("exits", ([
                "south"  : "/u/redl/houdian",
                "east"  : __DIR__"woshi",
                "north"  : "/u/redl/swing",
                "westup" : "/u/redl/suiroad1",
        ]));

        set("outdoors", "chengdu");
        //set("sleep_room", 1);
                //set("no_fight", 1); 
                set("no_rideto", 1);
                set("no_flyto", 1);

        set("room_owner", "紅蓮老祖");
        set("room_name", "蓮池");
        set("room_id", "redl");
        set("room_owner_id", "redl");
        set("room_position", "溪岸小路");
}

int valid_leave(object me, string dir)
{
        if ((dir == "north" || dir == "east") && (query("id", me) != "redl" && query("couple/couple_id", me) != "redl"))
                return notify_fail("那裡是私人地方不能過去。\n");

        return ::valid_leave(me, dir);
}

