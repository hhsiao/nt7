// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m蚩尤[2;37;0m[2;37;0m", ({"chiyou"}));        
        set("gender", "男性");                
        set("long", "而噢[2;37;0m
它是魔教倉庫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "moc");
        set("owner_name", "魔教倉庫");
        set_temp("owner", "moc");
        set_temp("owner_name", "魔教倉庫");
        ::setup();
}
