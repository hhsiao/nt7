// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小熊[2;37;0m[2;37;0m", ({"makkk"}));        
        set("gender", "男性");                
        set("long", "我的小熊[2;37;0m
它是小強強的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mafff");
        set("owner_name", "小強強");
        set_temp("owner", "mafff");
        set_temp("owner_name", "小強強");
        ::setup();
}
