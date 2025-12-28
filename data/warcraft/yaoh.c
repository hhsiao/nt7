// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸[2;37;0m[2;37;0m", ({"yaohs"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是把份的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaoh");
        set("owner_name", "把份");
        set_temp("owner", "yaoh");
        set_temp("owner_name", "把份");
        ::setup();
}
