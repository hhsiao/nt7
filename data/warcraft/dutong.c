// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m三足烏[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "女性");                
        set("long", "傳說中生活在太陽中的神鳥[2;37;0m
它是周毒通的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dutong");
        set("owner_name", "周毒通");
        set_temp("owner", "dutong");
        set_temp("owner_name", "周毒通");
        ::setup();
}
