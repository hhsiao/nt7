// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "hit chelonian[2;37;0m
它是冊那的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cena");
        set("owner_name", "冊那");
        set_temp("owner", "cena");
        set_temp("owner_name", "冊那");
        ::setup();
}
