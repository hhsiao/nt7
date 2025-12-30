// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蒙古馬[2;37;0m[2;37;0m", ({"rgg"}));        
        set("gender", "男性");                
        set("long", "一隻鳥[2;37;0m
它是不丟不頂的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "rew");
        set("owner_name", "不丟不頂");
        set_temp("owner", "rew");
        set_temp("owner_name", "不丟不頂");
        ::setup();
}
