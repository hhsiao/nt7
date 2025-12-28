// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蛟龍[2;37;0m[2;37;0m", ({"jiaolong"}));        
        set("gender", "男性");                
        set("long", "天下無敵[2;37;0m
它是牛君的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzc");
        set("owner_name", "牛君");
        set_temp("owner", "zzc");
        set_temp("owner_name", "牛君");
        ::setup();
}
