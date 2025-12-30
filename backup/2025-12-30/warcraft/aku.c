// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m酷[1;32m酷[1;35m神獸[2;37;0m[2;37;0m", ({"kuku"}));        
        set("gender", "女性");                
        set("long", "酷酷神獸[2;37;0m
它是黑星阿酷的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "aku");
        set("owner_name", "黑星阿酷");
        set_temp("owner", "aku");
        set_temp("owner_name", "黑星阿酷");
        ::setup();
}
