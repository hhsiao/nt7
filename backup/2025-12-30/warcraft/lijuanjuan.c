// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m真愛永恆[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "女性");                
        set("long", "我愛我的龍龍[2;37;0m
它是李娟娟的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lijuanjuan");
        set("owner_name", "李娟娟");
        set_temp("owner", "lijuanjuan");
        set_temp("owner_name", "李娟娟");
        ::setup();
}
