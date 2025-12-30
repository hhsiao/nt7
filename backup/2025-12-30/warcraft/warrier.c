// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m小白[2;37;0m[2;37;0m", ({"xiaobai"}));        
        set("gender", "女性");                
        set("long", "長著兩隻兔子耳朵的小動物[2;37;0m
它是字誰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "warrier");
        set("owner_name", "字誰");
        set_temp("owner", "warrier");
        set_temp("owner_name", "字誰");
        ::setup();
}
