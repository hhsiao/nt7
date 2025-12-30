// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("張揚[2;37;0m[2;37;0m", ({"zhangyanga"}));        
        set("gender", "女性");                
        set("long", "張揚[2;37;0m
它是毛毛寶寶的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "forredb");
        set("owner_name", "毛毛寶寶");
        set_temp("owner", "forredb");
        set_temp("owner_name", "毛毛寶寶");
        ::setup();
}
