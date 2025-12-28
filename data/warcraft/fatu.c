// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸饊[2;37;0m[2;37;0m", ({"aau"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是為藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatu");
        set("owner_name", "為藥");
        set_temp("owner", "fatu");
        set_temp("owner_name", "為藥");
        ::setup();
}
