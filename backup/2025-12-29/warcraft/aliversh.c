// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m可口可樂[2;37;0m[2;37;0m", ({"pesif"}));        
        set("gender", "男性");                
        set("long", "可口可樂[2;37;0m
它是阿爾八的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aliversh");
        set("owner_name", "阿爾八");
        set_temp("owner", "aliversh");
        set_temp("owner_name", "阿爾八");
        ::setup();
}
