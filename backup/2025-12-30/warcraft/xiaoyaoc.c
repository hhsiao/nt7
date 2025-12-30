// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("第三青龍[2;37;0m[2;37;0m", ({"sleepbagc"}));        
        set("gender", "男性");                
        set("long", "第三青龍[2;37;0m
它是小妖三號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaoyaoc");
        set("owner_name", "小妖三號");
        set_temp("owner", "xiaoyaoc");
        set_temp("owner_name", "小妖三號");
        ::setup();
}
