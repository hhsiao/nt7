// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸舞[2;37;0m[2;37;0m", ({"aaw"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是選藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatw");
        set("owner_name", "選藥");
        set_temp("owner", "fatw");
        set_temp("owner_name", "選藥");
        ::setup();
}
