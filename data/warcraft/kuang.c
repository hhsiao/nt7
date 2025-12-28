// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m風麒麟[1;37m[5m[2;37;0m[2;37;0m", ({"xkuang"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIY$風麒麟$HIY$$BLINK$[2;37;0m
它是狂風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kuang");
        set("owner_name", "狂風");
        set_temp("owner", "kuang");
        set_temp("owner_name", "狂風");
        ::setup();
}
