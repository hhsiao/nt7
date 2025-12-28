// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("靜恍恍惚惚[2;37;0m[2;37;0m", ({"jinghhhh"}));        
        set("gender", "男性");                
        set("long", "靜恍恍惚惚[2;37;0m
它是靜八的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jingh");
        set("owner_name", "靜八");
        set_temp("owner", "jingh");
        set_temp("owner_name", "靜八");
        ::setup();
}
