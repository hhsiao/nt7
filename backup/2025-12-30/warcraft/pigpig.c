// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m賓利[2;37;0m[2;37;0m", ({"pigpiga"}));        
        set("gender", "男性");                
        set("long", "賓利牌小轎車[2;37;0m
它是豬豬公子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pigpig");
        set("owner_name", "豬豬公子");
        set_temp("owner", "pigpig");
        set_temp("owner_name", "豬豬公子");
        ::setup();
}
