// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("破九天[2;37;0m[2;37;0m", ({"emalong"}));        
        set("gender", "男性");                
        set("long", "固體燃料[2;37;0m
它是滅諸佛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ema");
        set("owner_name", "滅諸佛");
        set_temp("owner", "ema");
        set_temp("owner_name", "滅諸佛");
        ::setup();
}
