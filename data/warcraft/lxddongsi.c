// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幻幻[2;37;0m[2;37;0m", ({"huansly"}));        
        set("gender", "男性");                
        set("long", "~~~~[2;37;0m
它是風冰月的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lxddongsi");
        set("owner_name", "風冰月");
        set_temp("owner", "lxddongsi");
        set_temp("owner_name", "風冰月");
        ::setup();
}
