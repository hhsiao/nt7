// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m黃金虎[2;37;0m[2;37;0m", ({"goldentiger"}));        
        set("gender", "男性");                
        set("long", "據說是高處不勝寒和老虎雜交的品種。[2;37;0m
它是漢軍鐵騎的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "knighter");
        set("owner_name", "漢軍鐵騎");
        set_temp("owner", "knighter");
        set_temp("owner_name", "漢軍鐵騎");
        ::setup();
}
