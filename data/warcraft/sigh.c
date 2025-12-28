// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m雷夔[2;37;0m[2;37;0m", ({"thunder_"}));        
        set("gender", "男性");                
        set("long", "其形狀如牛，形巨大，獨腳撐天，閃耀如日月般的光芒和聲若雷霆！[2;37;0m
它是一生嘆息的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sigh");
        set("owner_name", "一生嘆息");
        set_temp("owner", "sigh");
        set_temp("owner_name", "一生嘆息");
        ::setup();
}
