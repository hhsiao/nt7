// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀兒[2;37;0m[2;37;0m", ({"hongniao"}));        
        set("gender", "男性");                
        set("long", "朱雀兒[2;37;0m
它是康皓陽的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hskcm");
        set("owner_name", "康皓陽");
        set_temp("owner", "hskcm");
        set_temp("owner_name", "康皓陽");
        ::setup();
}
