// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是老鼠找貓的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lancer");
        set("owner_name", "老鼠找貓");
        set_temp("owner", "lancer");
        set_temp("owner_name", "老鼠找貓");
        ::setup();
}
