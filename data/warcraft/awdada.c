// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("放棄[2;37;0m[2;37;0m", ({"qqwqrq"}));        
        set("gender", "男性");                
        set("long", "ad [2;37;0m
它是啊訂單的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "awdada");
        set("owner_name", "啊訂單");
        set_temp("owner", "awdada");
        set_temp("owner_name", "啊訂單");
        ::setup();
}
