// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("五丫麒麟[2;37;0m[2;37;0m", ({"wacai"}));        
        set("gender", "女性");                
        set("long", "五丫麒麟[2;37;0m
它是吳吳雅的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "whe");
        set("owner_name", "吳吳雅");
        set_temp("owner", "whe");
        set_temp("owner_name", "吳吳雅");
        ::setup();
}
