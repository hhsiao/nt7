// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m夢想天空[2;37;0m[2;37;0m", ({"int"}));        
        set("gender", "男性");                
        set("long", "無[2;37;0m
它是修煉者的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pro");
        set("owner_name", "修煉者");
        set_temp("owner", "pro");
        set_temp("owner_name", "修煉者");
        ::setup();
}
