// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m綠狐[2;37;0m[2;37;0m", ({"greenfox"}));        
        set("gender", "女性");                
        set("long", "$HIG$綠狐[2;37;0m
它是燈水母的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "medusa");
        set("owner_name", "燈水母");
        set_temp("owner", "medusa");
        set_temp("owner_name", "燈水母");
        ::setup();
}
