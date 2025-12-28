// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小鳥[2;37;0m[2;37;0m", ({"sbird"}));        
        set("gender", "女性");                
        set("long", "小鳥[2;37;0m
它是黃衣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "avqueen");
        set("owner_name", "黃衣");
        set_temp("owner", "avqueen");
        set_temp("owner_name", "黃衣");
        ::setup();
}
