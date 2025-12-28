// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小青龍[2;37;0m[2;37;0m", ({"flydragon"}));        
        set("gender", "男性");                
        set("long", "一條上古時期的小青龍[2;37;0m
它是龍多多的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lyex");
        set("owner_name", "龍多多");
        set_temp("owner", "lyex");
        set_temp("owner_name", "龍多多");
        ::setup();
}
