// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火鳳凰[2;37;0m[2;37;0m", ({"hfh"}));        
        set("gender", "女性");                
        set("long", "火鳳凰[2;37;0m
它是那夜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "naye");
        set("owner_name", "那夜");
        set_temp("owner", "naye");
        set_temp("owner_name", "那夜");
        ::setup();
}
