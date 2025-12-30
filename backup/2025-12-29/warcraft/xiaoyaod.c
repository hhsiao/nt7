// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("第四青龍[2;37;0m[2;37;0m", ({"sleepbagd"}));        
        set("gender", "男性");                
        set("long", "第四青龍[2;37;0m
它是小妖四號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaoyaod");
        set("owner_name", "小妖四號");
        set_temp("owner", "xiaoyaod");
        set_temp("owner_name", "小妖四號");
        ::setup();
}
