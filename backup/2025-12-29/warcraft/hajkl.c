// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蛟龍[2;37;0m[2;37;0m", ({"jiaolong"}));        
        set("gender", "男性");                
        set("long", "蛟龍[2;37;0m
它是朱大能的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hajkl");
        set("owner_name", "朱大能");
        set_temp("owner", "hajkl");
        set_temp("owner_name", "朱大能");
        ::setup();
}
