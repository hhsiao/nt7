// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m烈火狂暴[1;33m麒麟[2;37;0m[2;37;0m", ({"flame"}));        
        set("gender", "男性");                
        set("long", "一隻金光閃耀全身冒著瘋狂烈焰的麒麟。它不屑的看了你一眼。[2;37;0m
它是暴力金剛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "berserk");
        set("owner_name", "暴力金剛");
        set_temp("owner", "berserk");
        set_temp("owner_name", "暴力金剛");
        ::setup();
}
