// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m飛得高[2;37;0m[2;37;0m", ({"fdg"}));        
        set("gender", "女性");                
        set("long", "飛得高[2;37;0m
它是走馬觀花的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zmgh");
        set("owner_name", "走馬觀花");
        set_temp("owner", "zmgh");
        set_temp("owner_name", "走馬觀花");
        ::setup();
}
