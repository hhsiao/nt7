// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m畢方[2;37;0m[2;37;0m", ({"flame"}));        
        set("gender", "男性");                
        set("long", "星星之火，可以毀天滅地！[2;37;0m
它是最終信仰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "limitless");
        set("owner_name", "最終信仰");
        set_temp("owner", "limitless");
        set_temp("owner_name", "最終信仰");
        ::setup();
}
