// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("松鼠貓貓[2;37;0m[2;37;0m", ({"smellycat"}));        
        set("gender", "男性");                
        set("long", "一隻活潑可愛的貓貓[2;37;0m
它是葫蘆貓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "brilla");
        set("owner_name", "葫蘆貓");
        set_temp("owner", "brilla");
        set_temp("owner_name", "葫蘆貓");
        ::setup();
}
