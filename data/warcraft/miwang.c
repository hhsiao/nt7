// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鋤頭[2;37;0m[2;37;0m", ({"qiankun_bag"}));        
        set("gender", "男性");                
        set("long", "出頭[2;37;0m
它是迷惘的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "miwang");
        set("owner_name", "迷惘");
        set_temp("owner", "miwang");
        set_temp("owner_name", "迷惘");
        ::setup();
}
