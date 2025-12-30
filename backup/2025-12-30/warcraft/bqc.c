// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("烏龜[2;37;0m[2;37;0m", ({"xdf"}));        
        set("gender", "女性");                
        set("long", "小烏龜[2;37;0m
它是獨孤三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bqc");
        set("owner_name", "獨孤三");
        set_temp("owner", "bqc");
        set_temp("owner_name", "獨孤三");
        ::setup();
}
