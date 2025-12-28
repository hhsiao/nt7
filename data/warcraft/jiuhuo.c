// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱武[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "銀鍠朱武[2;37;0m
它是九禍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jiuhuo");
        set("owner_name", "九禍");
        set_temp("owner", "jiuhuo");
        set_temp("owner_name", "九禍");
        ::setup();
}
