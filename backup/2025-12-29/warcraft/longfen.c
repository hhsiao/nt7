// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m語嫣[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "燕子烏的語嫣[2;37;0m
它是龍楓的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "longfen");
        set("owner_name", "龍楓");
        set_temp("owner", "longfen");
        set_temp("owner_name", "龍楓");
        ::setup();
}
