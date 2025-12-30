// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("電單車[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "新能源電單車，無需充電日行千里。[2;37;0m
它是小偷的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "thief");
        set("owner_name", "小偷");
        set_temp("owner", "thief");
        set_temp("owner_name", "小偷");
        ::setup();
}
