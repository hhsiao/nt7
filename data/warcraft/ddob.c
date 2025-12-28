// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m小蛇[2;37;0m[2;37;0m", ({"dragon_b"}));        
        set("gender", "女性");                
        set("long", "$BLK$小蛇[2;37;0m
它是符文二號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ddob");
        set("owner_name", "符文二號");
        set_temp("owner", "ddob");
        set_temp("owner_name", "符文二號");
        ::setup();
}
