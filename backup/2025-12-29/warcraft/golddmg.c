// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "alias m whistle zxcc[2;37;0m
它是黃金五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "golddmg");
        set("owner_name", "黃金五");
        set_temp("owner", "golddmg");
        set_temp("owner_name", "黃金五");
        ::setup();
}
