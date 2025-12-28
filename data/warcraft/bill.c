// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是趙子龍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bill");
        set("owner_name", "趙子龍");
        set_temp("owner", "bill");
        set_temp("owner_name", "趙子龍");
        ::setup();
}
