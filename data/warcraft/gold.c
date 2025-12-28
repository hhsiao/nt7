// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "            [2;37;0m
它是黃金搭檔的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gold");
        set("owner_name", "黃金搭檔");
        set_temp("owner", "gold");
        set_temp("owner_name", "黃金搭檔");
        ::setup();
}
