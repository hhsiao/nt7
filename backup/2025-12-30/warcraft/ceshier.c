// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎撒[2;37;0m[2;37;0m", ({"zuoqisa"}));        
        set("gender", "男性");                
        set("long", "請描述魔幻獸：(不可加顏色)[2;37;0m
它是丹王蛾的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ceshier");
        set("owner_name", "丹王蛾");
        set_temp("owner", "ceshier");
        set_temp("owner_name", "丹王蛾");
        ::setup();
}
