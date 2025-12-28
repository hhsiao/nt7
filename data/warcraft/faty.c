// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸期[2;37;0m[2;37;0m", ({"aay"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是組藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "faty");
        set("owner_name", "組藥");
        set_temp("owner", "faty");
        set_temp("owner_name", "組藥");
        ::setup();
}
