// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "女性");                
        set("long", "你中獎了.[2;37;0m
它是天外飛仙的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xue");
        set("owner_name", "天外飛仙");
        set_temp("owner", "xue");
        set_temp("owner_name", "天外飛仙");
        ::setup();
}
