// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬雀[2;37;0m[2;37;0m", ({"zqqqq"}));        
        set("gender", "女性");                
        set("long", "豬[2;37;0m
它是戀丹的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ldmd");
        set("owner_name", "戀丹");
        set_temp("owner", "ldmd");
        set_temp("owner_name", "戀丹");
        ::setup();
}
