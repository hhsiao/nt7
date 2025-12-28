// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龜仙人[2;37;0m[2;37;0m", ({"lvbiao"}));        
        set("gender", "女性");                
        set("long", "龜仙人[2;37;0m
它是空巫的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lbbj");
        set("owner_name", "空巫");
        set_temp("owner", "lbbj");
        set_temp("owner_name", "空巫");
        ::setup();
}
