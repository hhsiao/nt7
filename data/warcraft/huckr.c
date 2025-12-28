// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大無畏[2;37;0m[2;37;0m", ({"wuwei"}));        
        set("gender", "男性");                
        set("long", "$HIW$大無畏[2;37;0m
它是胡塗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "huckr");
        set("owner_name", "胡塗");
        set_temp("owner", "huckr");
        set_temp("owner_name", "胡塗");
        ::setup();
}
