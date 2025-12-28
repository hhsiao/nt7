// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幸福[2;37;0m[2;37;0m", ({"yaokuaile"}));        
        set("gender", "男性");                
        set("long", "幸福快樂[2;37;0m
它是高興的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "kuaile");
        set("owner_name", "高興");
        set_temp("owner", "kuaile");
        set_temp("owner_name", "高興");
        ::setup();
}
