// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m詩意[2;37;0m[2;37;0m", ({"picsyi"}));        
        set("gender", "男性");                
        set("long", "$HIY$詩意!1[2;37;0m
它是陸卜拾遺的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangsyi");
        set("owner_name", "陸卜拾遺");
        set_temp("owner", "dangsyi");
        set_temp("owner_name", "陸卜拾遺");
        ::setup();
}
