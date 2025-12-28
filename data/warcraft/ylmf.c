// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m風之麒麟[2;37;0m[2;37;0m", ({"ylmfm"}));        
        set("gender", "女性");                
        set("long", "風之麒麟[2;37;0m
它是雨林木風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ylmf");
        set("owner_name", "雨林木風");
        set_temp("owner", "ylmf");
        set_temp("owner_name", "雨林木風");
        ::setup();
}
