// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是發呆的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fadai");
        set("owner_name", "發呆");
        set_temp("owner", "fadai");
        set_temp("owner_name", "發呆");
        ::setup();
}
