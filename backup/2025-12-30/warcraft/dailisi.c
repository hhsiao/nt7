// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("慧雲[2;37;0m[2;37;0m", ({"huiyun"}));        
        set("gender", "男性");                
        set("long", "天音嫌者,美麗的人與[2;37;0m
它是戴麗絲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dailisi");
        set("owner_name", "戴麗絲");
        set_temp("owner", "dailisi");
        set_temp("owner_name", "戴麗絲");
        ::setup();
}
