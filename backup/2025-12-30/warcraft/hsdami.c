// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("我的馬[2;37;0m[2;37;0m", ({"mymama"}));        
        set("gender", "女性");                
        set("long", "我的馬[2;37;0m
它是是弄的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hsdami");
        set("owner_name", "是弄");
        set_temp("owner", "hsdami");
        set_temp("owner_name", "是弄");
        ::setup();
}
