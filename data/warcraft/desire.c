// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m冰封王座[2;37;0m[2;37;0m", ({"seal"}));        
        set("gender", "男性");                
        set("long", "俱往矣，數風流人物，還看今朝！[2;37;0m
它是談無慾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "desire");
        set("owner_name", "談無慾");
        set_temp("owner", "desire");
        set_temp("owner_name", "談無慾");
        ::setup();
}
