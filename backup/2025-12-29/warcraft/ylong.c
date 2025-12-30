// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m玉麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "玉麒麟[2;37;0m
它是雲龍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ylong");
        set("owner_name", "雲龍");
        set_temp("owner", "ylong");
        set_temp("owner_name", "雲龍");
        ::setup();
}
