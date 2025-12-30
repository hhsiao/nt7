// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("非影[2;37;0m[2;37;0m", ({"gogohappy"}));        
        set("gender", "女性");                
        set("long", "無[2;37;0m
它是雲淡的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "toho");
        set("owner_name", "雲淡");
        set_temp("owner", "toho");
        set_temp("owner_name", "雲淡");
        ::setup();
}
