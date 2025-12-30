// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天海翼[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "天海翼[2;37;0m
它是少林一號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sldm");
        set("owner_name", "少林一號");
        set_temp("owner", "sldm");
        set_temp("owner_name", "少林一號");
        ::setup();
}
