// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"cangkux"}));        
        set("gender", "女性");                
        set("long", "一隻小青蟲[2;37;0m
它是倉庫一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cangku");
        set("owner_name", "倉庫一");
        set_temp("owner", "cangku");
        set_temp("owner_name", "倉庫一");
        ::setup();
}
