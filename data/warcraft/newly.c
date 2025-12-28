// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿茲貓[2;37;0m[2;37;0m", ({"loy"}));        
        set("gender", "女性");                
        set("long", "阿茲貓[2;37;0m
它是高處勝寒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "newly");
        set("owner_name", "高處勝寒");
        set_temp("owner", "newly");
        set_temp("owner_name", "高處勝寒");
        ::setup();
}
