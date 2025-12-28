// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是武當米三的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ntdmc");
        set("owner_name", "武當米三");
        set_temp("owner", "ntdmc");
        set_temp("owner_name", "武當米三");
        ::setup();
}
