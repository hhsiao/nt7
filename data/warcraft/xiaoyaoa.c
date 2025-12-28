// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("第一青龍[2;37;0m[2;37;0m", ({"sleepbaga"}));        
        set("gender", "男性");                
        set("long", "第一青龍[2;37;0m
它是小妖一號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaoyaoa");
        set("owner_name", "小妖一號");
        set_temp("owner", "xiaoyaoa");
        set_temp("owner_name", "小妖一號");
        ::setup();
}
