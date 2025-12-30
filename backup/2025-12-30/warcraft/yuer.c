// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m萏氌[2;37;0m[2;37;0m", ({"danlu"}));        
        set("gender", "女性");                
        set("long", "萏氌[2;37;0m
它是禹二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yuer");
        set("owner_name", "禹二");
        set_temp("owner", "yuer");
        set_temp("owner_name", "禹二");
        ::setup();
}
