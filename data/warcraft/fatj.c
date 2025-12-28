// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸而[2;37;0m[2;37;0m", ({"aaj"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是請藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatj");
        set("owner_name", "請藥");
        set_temp("owner", "fatj");
        set_temp("owner_name", "請藥");
        ::setup();
}
