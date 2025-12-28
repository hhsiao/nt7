// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("歐威歐派[2;37;0m[2;37;0m", ({"sdfe"}));        
        set("gender", "男性");                
        set("long", "歐威歐派[2;37;0m
它是護腕的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kuc");
        set("owner_name", "護腕");
        set_temp("owner", "kuc");
        set_temp("owner_name", "護腕");
        ::setup();
}
