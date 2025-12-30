// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬雀[2;37;0m[2;37;0m", ({"zqqqq"}));        
        set("gender", "女性");                
        set("long", "豬[2;37;0m
它是聯丹的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ldme");
        set("owner_name", "聯丹");
        set_temp("owner", "ldme");
        set_temp("owner_name", "聯丹");
        ::setup();
}
