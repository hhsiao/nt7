// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m菩提[2;37;0m[2;37;0m", ({"puti"}));        
        set("gender", "女性");                
        set("long", "菩提本無樹[2;37;0m
它是須菩提的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bodhi");
        set("owner_name", "須菩提");
        set_temp("owner", "bodhi");
        set_temp("owner_name", "須菩提");
        ::setup();
}
