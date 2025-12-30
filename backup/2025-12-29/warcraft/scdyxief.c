// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m紅紅紅紅馬[2;37;0m[2;37;0m", ({"xief"}));        
        set("gender", "男性");                
        set("long", "一匹馬[2;37;0m
它是伯賞坤育的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "scdyxief");
        set("owner_name", "伯賞坤育");
        set_temp("owner", "scdyxief");
        set_temp("owner_name", "伯賞坤育");
        ::setup();
}
