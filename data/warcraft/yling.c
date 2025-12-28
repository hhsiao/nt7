// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"xuxu"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是天靈的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yling");
        set("owner_name", "天靈");
        set_temp("owner", "yling");
        set_temp("owner_name", "天靈");
        ::setup();
}
