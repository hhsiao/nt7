// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是武當米五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ntdmw");
        set("owner_name", "武當米五");
        set_temp("owner", "ntdmw");
        set_temp("owner_name", "武當米五");
        ::setup();
}
