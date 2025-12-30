// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸似[2;37;0m[2;37;0m", ({"aav"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是加藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatv");
        set("owner_name", "加藥");
        set_temp("owner", "fatv");
        set_temp("owner_name", "加藥");
        ::setup();
}
