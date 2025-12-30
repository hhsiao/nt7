// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("揮翅膀的鈔票[2;37;0m[2;37;0m", ({"money"}));        
        set("gender", "男性");                
        set("long", "飛走了...[2;37;0m
它是中大獎的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lucky");
        set("owner_name", "中大獎");
        set_temp("owner", "lucky");
        set_temp("owner_name", "中大獎");
        ::setup();
}
