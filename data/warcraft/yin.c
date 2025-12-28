// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[41;1m[1;37m小龍女[2;37;0m[2;37;0m", ({"longnv"}));        
        set("gender", "女性");                
        set("long", "古墓派 小龍女[2;37;0m
它是尹志平的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yin");
        set("owner_name", "尹志平");
        set_temp("owner", "yin");
        set_temp("owner_name", "尹志平");
        ::setup();
}
