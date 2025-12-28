#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "雁門關"NOR);
        set("long", @LONG
這裡就是「大宋」軍營了，一面大旗高高樹起，上面書著一個斗大的隸書
「宋」字，前面不遠就是宋軍元帥的帳營了。這裡駐守的宋軍是為了阻止遼國
難下入侵的關鍵屏障，一旦這裡被契丹攻破，那麼大宋就岌岌可危了！
LONG
);

        set("no_fly", "1");
        set("exits", ([ /* sizeof() == 5 */
               "south" :   "/d/guanwai/laolongtou",
               "north" :   __DIR__"shance",
        ]));

        set("objects", ([

        ]));

        setup();
}

