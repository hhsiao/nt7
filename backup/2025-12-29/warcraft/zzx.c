// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿黃[2;37;0m[2;37;0m", ({"zzxxxx"}));        
        set("gender", "男性");                
        set("long", "一隻小小鳥啊[2;37;0m
它是煩啦煩啦的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zzx");
        set("owner_name", "煩啦煩啦");
        set_temp("owner", "zzx");
        set_temp("owner_name", "煩啦煩啦");
        ::setup();
}
