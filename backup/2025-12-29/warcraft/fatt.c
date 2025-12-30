// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸餌[2;37;0m[2;37;0m", ({"aat"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是因藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatt");
        set("owner_name", "因藥");
        set_temp("owner", "fatt");
        set_temp("owner_name", "因藥");
        ::setup();
}
