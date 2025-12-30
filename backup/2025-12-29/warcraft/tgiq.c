// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青龍[2;37;0m[2;37;0m", ({"tgiqd"}));        
        set("gender", "男性");                
        set("long", "這其實是寶馬[2;37;0m
它是先天楊威的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tgiq");
        set("owner_name", "先天楊威");
        set_temp("owner", "tgiq");
        set_temp("owner_name", "先天楊威");
        ::setup();
}
