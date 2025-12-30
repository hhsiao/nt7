// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m仙鶴[2;37;0m[2;37;0m", ({"cay"}));        
        set("gender", "男性");                
        set("long", "$HIW$仙鶴[2;37;0m
它是張仲景的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zhongjing");
        set("owner_name", "張仲景");
        set_temp("owner", "zhongjing");
        set_temp("owner_name", "張仲景");
        ::setup();
}
