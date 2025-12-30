// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m滅絕師太[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "女性");                
        set("long", "滅絕師太[2;37;0m
它是見情的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "oooo");
        set("owner_name", "見情");
        set_temp("owner", "oooo");
        set_temp("owner_name", "見情");
        ::setup();
}
