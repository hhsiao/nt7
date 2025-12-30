// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬匹甲[2;37;0m[2;37;0m", ({"abaa"}));        
        set("gender", "男性");                
        set("long", "weq[2;37;0m
它是小兵甲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xba");
        set("owner_name", "小兵甲");
        set_temp("owner", "xba");
        set_temp("owner_name", "小兵甲");
        ::setup();
}
