// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("驚[2;37;0m[2;37;0m", ({"jingjing"}));        
        set("gender", "男性");                
        set("long", "驚[2;37;0m
它是驚天的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jingtian");
        set("owner_name", "驚天");
        set_temp("owner", "jingtian");
        set_temp("owner_name", "驚天");
        ::setup();
}
