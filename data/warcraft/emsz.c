// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "一隻麒麟[2;37;0m
它是專用雅人的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emsz");
        set("owner_name", "專用雅人");
        set_temp("owner", "emsz");
        set_temp("owner_name", "專用雅人");
        ::setup();
}
