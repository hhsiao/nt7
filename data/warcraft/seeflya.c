// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m白小[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "男性");                
        set("long", "小貓[2;37;0m
它是風飛一揚的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "seeflya");
        set("owner_name", "風飛一揚");
        set_temp("owner", "seeflya");
        set_temp("owner_name", "風飛一揚");
        ::setup();
}
