// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("學步車[2;37;0m[2;37;0m", ({"girlioi"}));        
        set("gender", "男性");                
        set("long", "學步車[2;37;0m
它是練習的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sshk");
        set("owner_name", "練習");
        set_temp("owner", "sshk");
        set_temp("owner_name", "練習");
        ::setup();
}
