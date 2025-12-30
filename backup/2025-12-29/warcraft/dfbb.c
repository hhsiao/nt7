// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m神鵰[2;37;0m[2;37;0m", ({"sdiao"}));        
        set("gender", "男性");                
        set("long", "這是救過斷臂楊過的遠古大雕[2;37;0m
它是東方不敗的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dfbb");
        set("owner_name", "東方不敗");
        set_temp("owner", "dfbb");
        set_temp("owner_name", "東方不敗");
        ::setup();
}
