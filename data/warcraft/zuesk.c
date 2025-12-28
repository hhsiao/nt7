// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33;43m葉黃[2;37;0m[2;37;0m", ({"zuesks"}));        
        set("gender", "男性");                
        set("long", "哈哈[2;37;0m
它是黃葉的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zuesk");
        set("owner_name", "黃葉");
        set_temp("owner", "zuesk");
        set_temp("owner_name", "黃葉");
        ::setup();
}
