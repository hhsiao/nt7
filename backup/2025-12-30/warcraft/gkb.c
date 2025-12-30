// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虎妹[2;37;0m[2;37;0m", ({"xbh"}));        
        set("gender", "男性");                
        set("long", "小虎妹。[2;37;0m
它是歐陽二的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "gkb");
        set("owner_name", "歐陽二");
        set_temp("owner", "gkb");
        set_temp("owner_name", "歐陽二");
        ::setup();
}
