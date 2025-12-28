// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騎馬兒[2;37;0m[2;37;0m", ({"qimaer"}));        
        set("gender", "女性");                
        set("long", "騎馬兒[2;37;0m
它是冶子的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "syer");
        set("owner_name", "冶子");
        set_temp("owner", "syer");
        set_temp("owner_name", "冶子");
        ::setup();
}
