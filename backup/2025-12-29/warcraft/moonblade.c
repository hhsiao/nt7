// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"xiaosan"}));        
        set("gender", "男性");                
        set("long", "遠古溶洞誕生的一頭異獸[2;37;0m
它是圓月彎刀的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "moonblade");
        set("owner_name", "圓月彎刀");
        set_temp("owner", "moonblade");
        set_temp("owner_name", "圓月彎刀");
        ::setup();
}
