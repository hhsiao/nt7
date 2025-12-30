// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zixc"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是絕代風華的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yqsdma");
        set("owner_name", "絕代風華");
        set_temp("owner", "yqsdma");
        set_temp("owner_name", "絕代風華");
        ::setup();
}
