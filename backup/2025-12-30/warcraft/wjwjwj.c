// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血傻[2;37;0m[2;37;0m", ({"super"}));        
        set("gender", "男性");                
        set("long", "血[2;37;0m
它是無獸的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wjwjwj");
        set("owner_name", "無獸");
        set_temp("owner", "wjwjwj");
        set_temp("owner_name", "無獸");
        ::setup();
}
