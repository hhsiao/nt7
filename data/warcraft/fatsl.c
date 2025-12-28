// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("長江[2;37;0m[2;37;0m", ({"fas"}));        
        set("gender", "男性");                
        set("long", "長江[2;37;0m
它是少銘少的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatsl");
        set("owner_name", "少銘少");
        set_temp("owner", "fatsl");
        set_temp("owner_name", "少銘少");
        ::setup();
}
