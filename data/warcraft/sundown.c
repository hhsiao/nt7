// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m亂[1;36m世[1;31m無[1;33m畏[2;37;0m[2;37;0m", ({"sunplay"}));        
        set("gender", "女性");                
        set("long", "亂世無畏[2;37;0m
它是大笨噗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sundown");
        set("owner_name", "大笨噗");
        set_temp("owner", "sundown");
        set_temp("owner_name", "大笨噗");
        ::setup();
}
