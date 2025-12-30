// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m六[1;32m脈[2;37;0m[2;37;0m[2;37;0m", ({"sixf"}));        
        set("gender", "女性");                
        set("long", "厲害的[2;37;0m
它是段六脈的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sixfinger");
        set("owner_name", "段六脈");
        set_temp("owner", "sixfinger");
        set_temp("owner_name", "段六脈");
        ::setup();
}
