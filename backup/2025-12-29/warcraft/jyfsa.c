// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是軒轅雪的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jyfsa");
        set("owner_name", "軒轅雪");
        set_temp("owner", "jyfsa");
        set_temp("owner_name", "軒轅雪");
        ::setup();
}
