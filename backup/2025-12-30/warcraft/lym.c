// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("拉克三大紀律[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "拉克三大紀律[2;37;0m
它是櫻桃三號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lym");
        set("owner_name", "櫻桃三號");
        set_temp("owner", "lym");
        set_temp("owner_name", "櫻桃三號");
        ::setup();
}
