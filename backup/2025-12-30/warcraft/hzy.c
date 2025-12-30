// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("五九式輕坦[2;37;0m[2;37;0m", ({"ybx"}));        
        set("gender", "男性");                
        set("long", "天朝國產坦克[2;37;0m
它是何琢言的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hzy");
        set("owner_name", "何琢言");
        set_temp("owner", "hzy");
        set_temp("owner_name", "何琢言");
        ::setup();
}
