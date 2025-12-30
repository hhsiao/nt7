// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("灰太狼[2;37;0m[2;37;0m", ({"hhh"}));        
        set("gender", "男性");                
        set("long", "老工，我要吃懶羊羊喲，西西[2;37;0m
它是紅太狼的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "htl");
        set("owner_name", "紅太狼");
        set_temp("owner", "htl");
        set_temp("owner_name", "紅太狼");
        ::setup();
}
