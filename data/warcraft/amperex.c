// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m諦聽[2;37;0m[2;37;0m", ({"listen"}));        
        set("gender", "男性");                
        set("long", "辨識世間萬物本質,透視眾生靈魂,免疫一切忽悠！！！[2;37;0m
它是素還真的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "amperex");
        set("owner_name", "素還真");
        set_temp("owner", "amperex");
        set_temp("owner_name", "素還真");
        ::setup();
}
