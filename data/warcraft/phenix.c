// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m五[1;32m毒[1;31m聖物[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "女性");                
        set("long", "五毒聖物[2;37;0m
它是藍鳳凰的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "phenix");
        set("owner_name", "藍鳳凰");
        set_temp("owner", "phenix");
        set_temp("owner_name", "藍鳳凰");
        ::setup();
}
