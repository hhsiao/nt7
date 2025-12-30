// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("西米露露[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "老大是經濟晚來風事發後[2;37;0m
它是周倉貳的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "btg");
        set("owner_name", "周倉貳");
        set_temp("owner", "btg");
        set_temp("owner_name", "周倉貳");
        ::setup();
}
