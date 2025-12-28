// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是松島楓的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ntby");
        set("owner_name", "松島楓");
        set_temp("owner", "ntby");
        set_temp("owner_name", "松島楓");
        ::setup();
}
