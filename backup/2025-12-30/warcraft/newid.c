// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獸獸[2;37;0m[2;37;0m", ({"newidid"}));        
        set("gender", "男性");                
        set("long", "獸獸[2;37;0m
它是飛飛楊的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "newid");
        set("owner_name", "飛飛楊");
        set_temp("owner", "newid");
        set_temp("owner_name", "飛飛楊");
        ::setup();
}
