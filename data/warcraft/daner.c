// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("祝福二[2;37;0m[2;37;0m", ({"der"}));        
        set("gender", "男性");                
        set("long", "小小[2;37;0m
它是但氏二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "daner");
        set("owner_name", "但氏二");
        set_temp("owner", "daner");
        set_temp("owner_name", "但氏二");
        ::setup();
}
