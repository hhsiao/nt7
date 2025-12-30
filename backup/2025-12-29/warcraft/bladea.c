// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("胯下少女[2;37;0m[2;37;0m", ({"bladealong"}));        
        set("gender", "男性");                
        set("long", "sigh[2;37;0m
它是刀無命的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bladea");
        set("owner_name", "刀無命");
        set_temp("owner", "bladea");
        set_temp("owner_name", "刀無命");
        ::setup();
}
