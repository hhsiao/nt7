// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[33m拉[33m土[33m車[2;37;0m[2;37;0m", ({"fatt"}));        
        set("gender", "女性");                
        set("long", "拉土車[2;37;0m
它是煉藥四的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatd");
        set("owner_name", "煉藥四");
        set_temp("owner", "fatd");
        set_temp("owner_name", "煉藥四");
        ::setup();
}
