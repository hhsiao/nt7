// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("舌燦蓮花[2;37;0m[2;37;0m", ({"lick"}));        
        set("gender", "女性");                
        set("long", "舔一下...[2;37;0m
它是小嘴冰涼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kiss");
        set("owner_name", "小嘴冰涼");
        set_temp("owner", "kiss");
        set_temp("owner_name", "小嘴冰涼");
        ::setup();
}
