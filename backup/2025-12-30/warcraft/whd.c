// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("四丫麒麟[2;37;0m[2;37;0m", ({"whdride"}));        
        set("gender", "女性");                
        set("long", "四丫麒麟[2;37;0m
它是吳四丫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "whd");
        set("owner_name", "吳四丫");
        set_temp("owner", "whd");
        set_temp("owner_name", "吳四丫");
        ::setup();
}
