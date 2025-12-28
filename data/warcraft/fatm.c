// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸五[2;37;0m[2;37;0m", ({"aamm"}));        
        set("gender", "女性");                
        set("long", "我的魔幻獸[2;37;0m
它是的藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fatm");
        set("owner_name", "的藥");
        set_temp("owner", "fatm");
        set_temp("owner_name", "的藥");
        ::setup();
}
