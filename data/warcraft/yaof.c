// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸[2;37;0m[2;37;0m", ({"yaofs"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是六份的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yaof");
        set("owner_name", "六份");
        set_temp("owner", "yaof");
        set_temp("owner_name", "六份");
        ::setup();
}
