// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("圖圖[2;37;0m[2;37;0m", ({"tta"}));        
        set("gender", "男性");                
        set("long", "xx[2;37;0m
它是圖一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ttza");
        set("owner_name", "圖一");
        set_temp("owner", "ttza");
        set_temp("owner_name", "圖一");
        ::setup();
}
