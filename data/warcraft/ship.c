// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m踏雪[5m[1;34m烏錐[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身烏黑宛如錦緞，唯有四蹄白色，追風逐電，龍吟虎相。[2;37;0m
它是楊三泰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ship");
        set("owner_name", "楊三泰");
        set_temp("owner", "ship");
        set_temp("owner_name", "楊三泰");
        ::setup();
}
