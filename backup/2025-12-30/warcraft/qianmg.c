// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"t_beijing"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是飲風而醉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmg");
        set("owner_name", "飲風而醉");
        set_temp("owner", "qianmg");
        set_temp("owner_name", "飲風而醉");
        ::setup();
}
