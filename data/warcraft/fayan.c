// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("摩托車[2;37;0m[2;37;0m", ({"moto"}));        
        set("gender", "女性");                
        set("long", "這是一輛摩托車[2;37;0m
它是本國領導的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "fayan");
        set("owner_name", "本國領導");
        set_temp("owner", "fayan");
        set_temp("owner_name", "本國領導");
        ::setup();
}
