// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸衣[2;37;0m[2;37;0m", ({"aas"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是於藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fats");
        set("owner_name", "於藥");
        set_temp("owner", "fats");
        set_temp("owner_name", "於藥");
        ::setup();
}
