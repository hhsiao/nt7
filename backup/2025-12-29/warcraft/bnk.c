// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m道風翩翩[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "$HIC$道風翩翩[2;37;0m
它是瘋歐陽的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "bnk");
        set("owner_name", "瘋歐陽");
        set_temp("owner", "bnk");
        set_temp("owner_name", "瘋歐陽");
        ::setup();
}
