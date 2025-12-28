// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m混雷嘯[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "人中呂布 馬中雷嘯[2;37;0m
它是史萊姆的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "oxemii");
        set("owner_name", "史萊姆");
        set_temp("owner", "oxemii");
        set_temp("owner_name", "史萊姆");
        ::setup();
}
