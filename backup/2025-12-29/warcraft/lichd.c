// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獨孤瘋豬[2;37;0m[2;37;0m", ({"lichasm"}));        
        set("gender", "男性");                
        set("long", "獨孤瘋豬[2;37;0m
它是師傅來了的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lichd");
        set("owner_name", "師傅來了");
        set_temp("owner", "lichd");
        set_temp("owner_name", "師傅來了");
        ::setup();
}
