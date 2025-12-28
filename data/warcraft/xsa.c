// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是龍象一號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xsa");
        set("owner_name", "龍象一號");
        set_temp("owner", "xsa");
        set_temp("owner_name", "龍象一號");
        ::setup();
}
