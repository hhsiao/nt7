// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙狗[2;37;0m
它是鳳腰帶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lfengh");
        set("owner_name", "鳳腰帶");
        set_temp("owner", "lfengh");
        set_temp("owner_name", "鳳腰帶");
        ::setup();
}
