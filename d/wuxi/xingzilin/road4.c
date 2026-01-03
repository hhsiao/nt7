// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create() {
    set("short", "杏林小道");
    set("long", @LONG
這是林中小路，高大的杏樹密佈。濃霧飄繞五丈外不可見人，周圍
殺喊的聲音不時傳來。西面遠望去有一大堆柴禾擋著去路，柴禾縫隙中
隱隱約約露出個黑黝黝的山洞口。
LONG);
    set("no_sleep_room", 1);
    set("no_magic", 1);
    set("exits", ([
        "north": __DIR__"dynamic/dxlin1",
        "west": __FILE__,
        "south": __DIR__"xxlin9"
        ]));
    set("objects", ([
        "/clone/npc/walker"  : 3
        ]));

    setup();


}

int valid_leave(object me, string dir) {
    if (dir == "west" && ! playerp(me)) return 0;   //阻擋npc逃進安全區

    if (dir == "west")
    {
        if (me->is_fighting())  //可能處於被追殺中
        {
            if (random(2))
            {
                tell_object(me, YEL"你急急忙忙地把柴禾扒開一個縫隙，縱身鑽了進去......\n"NOR);
                me->move(__DIR__"sleeproom");
                tell_object(me, CYN "你驚魂未定，但發現後面的腳步聲似乎停下來了。\n" NOR );
                return 1;
            }
            else
            {
                me->start_busy(2 + random(2));
                return notify_fail(YEL"你嚇得亡魂大冒，衝到柴禾堆前瘋狂地亂刨......\n"NOR);
            }
        }
        else
        {
            tell_object(me, YEL"你不慌不忙地把柴禾扒開一個縫隙，縱身鑽了進去......\n"NOR);
            me->move(__DIR__"sleeproom");
            return 1;
        }
    }

    return ::valid_leave(me, dir);
}
