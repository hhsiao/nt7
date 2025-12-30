// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "豬[2;37;0m
它是土西遊的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txy");
        set("owner_name", "土西遊");
        set_temp("owner", "txy");
        set_temp("owner_name", "土西遊");
        ::setup();
}
