// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"lone"}));        
        set("gender", "男性");                
        set("long", "小龍[2;37;0m
它是可愛天使的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mina");
        set("owner_name", "可愛天使");
        set_temp("owner", "mina");
        set_temp("owner_name", "可愛天使");
        ::setup();
}
