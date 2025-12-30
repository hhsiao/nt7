// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "一隻麒麟[2;37;0m
它是馬民哲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emsd");
        set("owner_name", "馬民哲");
        set_temp("owner", "emsd");
        set_temp("owner_name", "馬民哲");
        ::setup();
}
