// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哈哈[2;37;0m[2;37;0m", ({"kkkkk"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是如夢的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cterm");
        set("owner_name", "如夢");
        set_temp("owner", "cterm");
        set_temp("owner_name", "如夢");
        ::setup();
}
