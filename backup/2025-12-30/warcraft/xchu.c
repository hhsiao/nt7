// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m抱月[1;34m烏騅[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "這匹馬全身烏黑宛如錦緞，腹部有個白月牙，龍吟虎相。[2;37;0m
它是許褚的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xchu");
        set("owner_name", "許褚");
        set_temp("owner", "xchu");
        set_temp("owner_name", "許褚");
        ::setup();
}
