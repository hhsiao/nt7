// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m愛騎[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIY$愛騎[2;37;0m
它是王昭娟的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wangzhjuan");
        set("owner_name", "王昭娟");
        set_temp("owner", "wangzhjuan");
        set_temp("owner_name", "王昭娟");
        ::setup();
}
