// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("拂櫻[2;37;0m[2;37;0m", ({"fuying"}));        
        set("gender", "男性");                
        set("long", "拂櫻齋[2;37;0m
它是凱旋侯的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kaixuanhou");
        set("owner_name", "凱旋侯");
        set_temp("owner", "kaixuanhou");
        set_temp("owner_name", "凱旋侯");
        ::setup();
}
