// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小依[2;37;0m[2;37;0m", ({"feeling"}));        
        set("gender", "女性");                
        set("long", "無[2;37;0m
它是謝七的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "toko");
        set("owner_name", "謝七");
        set_temp("owner", "toko");
        set_temp("owner_name", "謝七");
        ::setup();
}
