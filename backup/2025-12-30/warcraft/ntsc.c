// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蝴蝶[2;37;0m[2;37;0m", ({"butterfly"}));        
        set("gender", "男性");                
        set("long", "一隻麒麟[2;37;0m
它是陳恩的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ntsc");
        set("owner_name", "陳恩");
        set_temp("owner", "ntsc");
        set_temp("owner_name", "陳恩");
        ::setup();
}
