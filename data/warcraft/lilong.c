// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m真愛永恆[2;37;0m[2;37;0m", ({"ilovejuan"}));        
        set("gender", "男性");                
        set("long", "我愛我的娟娟[2;37;0m
它是李龍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lilong");
        set("owner_name", "李龍");
        set_temp("owner", "lilong");
        set_temp("owner_name", "李龍");
        ::setup();
}
