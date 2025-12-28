// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("冥晶[2;37;0m[2;37;0m", ({"sameg"}));        
        set("gender", "男性");                
        set("long", "一隻高大威猛冷酷的青色長龍，黑夜中透出兩隻綠瑩瑩的眼睛。[2;37;0m
它是天青的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "samesame");
        set("owner_name", "天青");
        set_temp("owner", "samesame");
        set_temp("owner_name", "天青");
        ::setup();
}
