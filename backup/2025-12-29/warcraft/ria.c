// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("傢俱店[2;37;0m[2;37;0m", ({"qqqqq"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是日啊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ria");
        set("owner_name", "日啊");
        set_temp("owner", "ria");
        set_temp("owner_name", "日啊");
        ::setup();
}
