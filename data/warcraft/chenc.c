// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m真龍[2;37;0m[2;37;0m", ({"deep"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIC$真龍！[2;37;0m
它是成真的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chenc");
        set("owner_name", "成真");
        set_temp("owner", "chenc");
        set_temp("owner_name", "成真");
        ::setup();
}
