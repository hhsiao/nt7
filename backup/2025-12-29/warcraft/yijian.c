// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m七[1;31m彩[1;32m瑞[1;35m獸[2;37;0m[2;37;0m", ({"qicairuish"}));        
        set("gender", "男性");                
        set("long", "祥瑞長壽[2;37;0m
它是天一劍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yijian");
        set("owner_name", "天一劍");
        set_temp("owner", "yijian");
        set_temp("owner_name", "天一劍");
        ::setup();
}
