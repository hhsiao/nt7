// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虎獅獸[2;37;0m[2;37;0m", ({"hss"}));        
        set("gender", "男性");                
        set("long", "那就是一個猛啊，嘿嘿[2;37;0m
它是懶狼狼的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lyy");
        set("owner_name", "懶狼狼");
        set_temp("owner", "lyy");
        set_temp("owner_name", "懶狼狼");
        ::setup();
}
