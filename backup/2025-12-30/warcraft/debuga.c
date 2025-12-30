// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;37m玉麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "這是一隻九天十地菩薩搖頭怕怕霹靂精光玉麒麟。[2;37;0m
它是武當大米的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "debuga");
        set("owner_name", "武當大米");
        set_temp("owner", "debuga");
        set_temp("owner_name", "武當大米");
        ::setup();
}
