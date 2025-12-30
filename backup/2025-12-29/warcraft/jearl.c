// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m小[1;36m雉[1;36m[2;37;0m[2;37;0m", ({"zhi"}));        
        set("gender", "男性");                
        set("long", "看起來像是傳說中的龍[2;37;0m
它是小誅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jearl");
        set("owner_name", "小誅");
        set_temp("owner", "jearl");
        set_temp("owner_name", "小誅");
        ::setup();
}
