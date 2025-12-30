// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m取名字這麼難[2;37;0m[2;37;0m", ({"qwe"}));        
        set("gender", "男性");                
        set("long", "shit[2;37;0m
它是九陽的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jiuy");
        set("owner_name", "九陽");
        set_temp("owner", "jiuy");
        set_temp("owner_name", "九陽");
        ::setup();
}
