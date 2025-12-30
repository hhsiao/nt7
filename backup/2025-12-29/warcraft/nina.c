// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("靈雀[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "女性");                
        set("long", "海妮娜的靈獸[2;37;0m
它是海妮娜的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "nina");
        set("owner_name", "海妮娜");
        set_temp("owner", "nina");
        set_temp("owner_name", "海妮娜");
        ::setup();
}
