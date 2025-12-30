// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m航空母艦[2;37;0m[2;37;0m", ({"hkmj"}));        
        set("gender", "女性");                
        set("long", "$HIW$航空母艦[2;37;0m
它是幾個人的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "jgr");
        set("owner_name", "幾個人");
        set_temp("owner", "jgr");
        set_temp("owner_name", "幾個人");
        ::setup();
}
