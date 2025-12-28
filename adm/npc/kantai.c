#include <ansi.h>
inherit ROOM;

int is_chat_room() { return 1; }

void create() {
        set("short", "比武看臺");
        set("long", @LONG
這裡是比武場的看臺。現在已經是人聲鼎沸，群雄議論紛紛，都在猜
測誰能折桂。四周有些桌子。
LONG
    );
        set("exits", ([
                "down"  : "/d/huashan/houzhiwangyu",
        ]));
        
        set("no_fight", 1);
        set("outdoors", "huashan" ); 

        setup();
}

int valid_leave(object me, string dir) 
{
        delete_temp("flag_hslj", me);
        return ::valid_leave(me, dir);
}
