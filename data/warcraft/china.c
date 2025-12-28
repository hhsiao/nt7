// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m火麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "這是一隻九天十地菩薩搖頭怕怕霹靂精光火麒麟。[2;37;0m
它是炎黃子孫的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "china");
        set("owner_name", "炎黃子孫");
        set_temp("owner", "china");
        set_temp("owner_name", "炎黃子孫");
        ::setup();
}
