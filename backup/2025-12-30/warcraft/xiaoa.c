// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("休閒鞋[2;37;0m[2;37;0m", ({"lllll"}));        
        set("gender", "女性");                
        set("long", "休閒鞋[2;37;0m
它是寶寶誒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaoa");
        set("owner_name", "寶寶誒");
        set_temp("owner", "xiaoa");
        set_temp("owner_name", "寶寶誒");
        ::setup();
}
