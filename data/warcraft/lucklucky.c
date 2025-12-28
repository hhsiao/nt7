// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m招[5m[1;33m財[2;37;0m[1;36m進[5m[1;33m寶[2;37;0m[2;37;0m[2;37;0m", ({"treasure"}));        
        set("gender", "男性");                
        set("long", "財寶！！[2;37;0m
它是招財貓的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lucklucky");
        set("owner_name", "招財貓");
        set_temp("owner", "lucklucky");
        set_temp("owner_name", "招財貓");
        ::setup();
}
