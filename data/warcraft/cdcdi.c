// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zqg"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是驚天動地的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cdcdi");
        set("owner_name", "驚天動地");
        set_temp("owner", "cdcdi");
        set_temp("owner_name", "驚天動地");
        ::setup();
}
