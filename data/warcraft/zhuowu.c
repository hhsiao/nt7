// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小珊瑚蟲[2;37;0m[2;37;0m", ({"coral"}));        
        set("gender", "男性");                
        set("long", "蹁躚浮游，夢幻空花！[2;37;0m
它是卓無航的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zhuowu");
        set("owner_name", "卓無航");
        set_temp("owner", "zhuowu");
        set_temp("owner_name", "卓無航");
        ::setup();
}
