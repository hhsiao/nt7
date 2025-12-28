// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m烤鴨[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "hahaha[2;37;0m
它是孤獨米大的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "koi");
        set("owner_name", "孤獨米大");
        set_temp("owner", "koi");
        set_temp("owner_name", "孤獨米大");
        ::setup();
}
