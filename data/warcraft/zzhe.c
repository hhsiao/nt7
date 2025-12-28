// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("空空[2;37;0m[2;37;0m", ({"ppp"}));        
        set("gender", "男性");                
        set("long", "空間咯[2;37;0m
它是恆六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzhe");
        set("owner_name", "恆六");
        set_temp("owner", "zzhe");
        set_temp("owner_name", "恆六");
        ::setup();
}
