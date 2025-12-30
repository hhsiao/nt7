// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("的會話[2;37;0m[2;37;0m", ({"opop"}));        
        set("gender", "男性");                
        set("long", "傢俱家電[2;37;0m
它是毒打貓貓的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "duda");
        set("owner_name", "毒打貓貓");
        set_temp("owner", "duda");
        set_temp("owner_name", "毒打貓貓");
        ::setup();
}
