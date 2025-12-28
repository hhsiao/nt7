// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "山洞");
        set("long", 
"這是山腹裡一片很寬闊的地方，頂高七八丈，方圓四五十丈。洞的正\n"
"中央有一座傳送陣("CYN"enter"NOR")，陣旁臺上有張蒲團，結跏趺坐著一個道人。\n"
);

         set("exits",([ /* sizeof() == 1 */
                 "enter" : __DIR__"suistone",
         ]));

        set("objects", ([
                __DIR__"obj/daoren" : 1,
        ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
                        set("get_time", time());
        setup();
        
}

int valid_leave(object me, string dir)
{
                if (objectp(present("dao ren", this_object()))) {
                tell_object(me, NOR "你幻聽到“哼..”的一聲，眼前一陣模糊，竟未能離開原地半步。\n" NOR);
                return -1;
                }
        if (dir == "enter" && playerp(me)) {
                tell_object(me, YEL "你振了振衣袖，強作鎮定地跨進了傳送陣。\n" NOR
                                                HIY "空間亂流不停地撕裂扭曲，轉眼到了隨風石。\n" NOR);
        }

        return ::valid_leave(me, dir);
}

