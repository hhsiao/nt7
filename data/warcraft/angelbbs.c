// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m神[1;31m獸[1;36m青[1;35m龍[2;37;0m[2;37;0m", ({"xboss"}));        
        set("gender", "男性");                
        set("long", "這是一隻九天十地菩薩搖頭怕怕霹靂精光遠古神獸之青龍。[2;37;0m
它是五毒教主的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "angelbbs");
        set("owner_name", "五毒教主");
        set_temp("owner", "angelbbs");
        set_temp("owner_name", "五毒教主");
        ::setup();
}
