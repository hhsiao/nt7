// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m墨玉麒麟[2;37;0m[2;37;0m[2;37;0m", ({"moyu"}));        
        set("gender", "女性");                
        set("long", "墨玉麒麟[2;37;0m
它是葉綠一風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesa");
        set("owner_name", "葉綠一風");
        set_temp("owner", "zuesa");
        set_temp("owner_name", "葉綠一風");
        ::setup();
}
