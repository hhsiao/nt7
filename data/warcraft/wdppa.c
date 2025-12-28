// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啊[2;37;0m[2;37;0m", ({"olo"}));        
        set("gender", "女性");                
        set("long", "啊[2;37;0m
它是武當師一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppa");
        set("owner_name", "武當師一");
        set_temp("owner", "wdppa");
        set_temp("owner_name", "武當師一");
        ::setup();
}
