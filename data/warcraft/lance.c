// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是麻痺曹丹的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lance");
        set("owner_name", "麻痺曹丹");
        set_temp("owner", "lance");
        set_temp("owner_name", "麻痺曹丹");
        ::setup();
}
