// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;34m愛騎[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "$BLINK$$HIB$愛騎[2;37;0m
它是呂娟的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lvjuan");
        set("owner_name", "呂娟");
        set_temp("owner", "lvjuan");
        set_temp("owner_name", "呂娟");
        ::setup();
}
