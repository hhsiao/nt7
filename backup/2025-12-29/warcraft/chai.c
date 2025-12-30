// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雅雅[2;37;0m[2;37;0m", ({"yayaya"}));        
        set("gender", "女性");                
        set("long", "雅雅的小寶寶[2;37;0m
它是小婭婭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "chai");
        set("owner_name", "小婭婭");
        set_temp("owner", "chai");
        set_temp("owner_name", "小婭婭");
        ::setup();
}
