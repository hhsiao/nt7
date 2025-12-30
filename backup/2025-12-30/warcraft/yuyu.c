// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火燒雲[2;37;0m[2;37;0m", ({"yun"}));        
        set("gender", "男性");                
        set("long", "$HIR$火燒雲[2;37;0m
它是雙魚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yuyu");
        set("owner_name", "雙魚");
        set_temp("owner", "yuyu");
        set_temp("owner_name", "雙魚");
        ::setup();
}
