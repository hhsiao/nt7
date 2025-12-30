// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m大衍[1;36m分光獸[2;37;0m[2;37;0m", ({"hufei_dragon"}));        
        set("gender", "男性");                
        set("long", "一隻神奇的小野獸。[2;37;0m
它是胡飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hufei");
        set("owner_name", "胡飛");
        set_temp("owner", "hufei");
        set_temp("owner_name", "胡飛");
        ::setup();
}
