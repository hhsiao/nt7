// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("吊睛白額大貓[2;37;0m[2;37;0m", ({"akb"}));        
        set("gender", "男性");                
        set("long", "通體雪白，無一根雜毛[2;37;0m
它是伯賞坤毓的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "scdyxie");
        set("owner_name", "伯賞坤毓");
        set_temp("owner", "scdyxie");
        set_temp("owner_name", "伯賞坤毓");
        ::setup();
}
