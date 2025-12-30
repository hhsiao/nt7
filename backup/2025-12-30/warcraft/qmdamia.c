// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m龍大[2;37;0m[2;37;0m", ({"qmdamiaa"}));        
        set("gender", "男性");                
        set("long", "----------[2;37;0m
它是王一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qmdamia");
        set("owner_name", "王一");
        set_temp("owner", "qmdamia");
        set_temp("owner_name", "王一");
        ::setup();
}
