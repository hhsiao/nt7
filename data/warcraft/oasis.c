// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"oasispet"}));        
        set("gender", "男性");                
        set("long", "描述什麼[2;37;0m
它是綠洲綠的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "oasis");
        set("owner_name", "綠洲綠");
        set_temp("owner", "oasis");
        set_temp("owner_name", "綠洲綠");
        ::setup();
}
