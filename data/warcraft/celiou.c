// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳳凰[2;37;0m[2;37;0m", ({"huofenghuang"}));        
        set("gender", "女性");                
        set("long", "一隻火鳳凰，正鳳翔九天之上。[2;37;0m
它是稍微絲襪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "celiou");
        set("owner_name", "稍微絲襪");
        set_temp("owner", "celiou");
        set_temp("owner_name", "稍微絲襪");
        ::setup();
}
