// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("拉迪達[2;37;0m[2;37;0m", ({"ladida"}));        
        set("gender", "女性");                
        set("long", "拉迪達[2;37;0m
它是桑幫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sanbang");
        set("owner_name", "桑幫");
        set_temp("owner", "sanbang");
        set_temp("owner_name", "桑幫");
        ::setup();
}
