// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幫用[2;37;0m[2;37;0m", ({"bangyon"}));        
        set("gender", "女性");                
        set("long", "幫用[2;37;0m
它是用幫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yonbang");
        set("owner_name", "用幫");
        set_temp("owner", "yonbang");
        set_temp("owner_name", "用幫");
        ::setup();
}
