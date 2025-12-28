// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qsq"}));        
        set("gender", "男性");                
        set("long", "幻獸呀！請你以最深的靈性，聆聽我的傾訴[2;37;0m
它是城化糞的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "iwu");
        set("owner_name", "城化糞");
        set_temp("owner", "iwu");
        set_temp("owner_name", "城化糞");
        ::setup();
}
