// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("暖麒麟[2;37;0m[2;37;0m", ({"fgs"}));        
        set("gender", "男性");                
        set("long", "一隻麒麟[2;37;0m
它是鐵犀牛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jkl");
        set("owner_name", "鐵犀牛");
        set_temp("owner", "jkl");
        set_temp("owner_name", "鐵犀牛");
        ::setup();
}
