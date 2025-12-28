// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m渡鴉[2;37;0m[2;37;0m", ({"duya"}));        
        set("gender", "女性");                
        set("long", "赤紅色的狂鴉[2;37;0m
它是輝夜的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "huiye");
        set("owner_name", "輝夜");
        set_temp("owner", "huiye");
        set_temp("owner_name", "輝夜");
        ::setup();
}
