// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"tgiwd"}));        
        set("gender", "男性");                
        set("long", "你看不見我[2;37;0m
它是實驗五毒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tgiw");
        set("owner_name", "實驗五毒");
        set_temp("owner", "tgiw");
        set_temp("owner_name", "實驗五毒");
        ::setup();
}
