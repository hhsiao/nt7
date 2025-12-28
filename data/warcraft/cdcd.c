// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是歷練高手的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "cdcd");
        set("owner_name", "歷練高手");
        set_temp("owner", "cdcd");
        set_temp("owner_name", "歷練高手");
        ::setup();
}
