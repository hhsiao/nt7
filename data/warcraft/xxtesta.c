// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m人參[2;37;0m[2;37;0m", ({"xxtestaa"}));        
        set("gender", "男性");                
        set("long", "阿[2;37;0m
它是星宿人參的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xxtesta");
        set("owner_name", "星宿人參");
        set_temp("owner", "xxtesta");
        set_temp("owner_name", "星宿人參");
        ::setup();
}
