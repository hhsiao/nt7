// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m玉靈散[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "$HIC$玉靈散[2;37;0m
它是玉清散的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "two");
        set("owner_name", "玉清散");
        set_temp("owner", "two");
        set_temp("owner_name", "玉清散");
        ::setup();
}
