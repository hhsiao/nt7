// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m白貓[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "男性");                
        set("long", "一隻小貓[2;37;0m
它是風飛七揚的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "seeflyg");
        set("owner_name", "風飛七揚");
        set_temp("owner", "seeflyg");
        set_temp("owner_name", "風飛七揚");
        ::setup();
}
