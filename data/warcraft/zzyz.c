// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是空像的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzyz");
        set("owner_name", "空像");
        set_temp("owner", "zzyz");
        set_temp("owner_name", "空像");
        ::setup();
}
