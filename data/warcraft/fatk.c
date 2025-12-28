// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸三[2;37;0m[2;37;0m", ({"aak"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是入藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatk");
        set("owner_name", "入藥");
        set_temp("owner", "fatk");
        set_temp("owner_name", "入藥");
        ::setup();
}
