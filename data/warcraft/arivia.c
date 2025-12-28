// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m露[5m[1;37m露[2;37;0m[2;37;0m", ({"lili"}));        
        set("gender", "女性");                
        set("long", "只[2;37;0m
它是擼斷腸的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "arivia");
        set("owner_name", "擼斷腸");
        set_temp("owner", "arivia");
        set_temp("owner_name", "擼斷腸");
        ::setup();
}
