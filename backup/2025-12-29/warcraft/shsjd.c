// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("一群烏鴉[2;37;0m[2;37;0m", ({"xiaojj"}));        
        set("gender", "男性");                
        set("long", "一群烏鴉[2;37;0m
它是洪九兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shsjd");
        set("owner_name", "洪九兒");
        set_temp("owner", "shsjd");
        set_temp("owner_name", "洪九兒");
        ::setup();
}
