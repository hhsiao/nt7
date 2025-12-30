// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("王牌神獸[2;37;0m[2;37;0m", ({"acerxw"}));        
        set("gender", "男性");                
        set("long", "流風之迴雪之神獸[2;37;0m
它是流風迴雪的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lfhx");
        set("owner_name", "流風迴雪");
        set_temp("owner", "lfhx");
        set_temp("owner_name", "流風迴雪");
        ::setup();
}
