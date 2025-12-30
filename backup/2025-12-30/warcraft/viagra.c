// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "中國古代神話傳說中的神獸，據說能活兩千年。[2;37;0m
它是製藥機的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "viagra");
        set("owner_name", "製藥機");
        set_temp("owner", "viagra");
        set_temp("owner_name", "製藥機");
        ::setup();
}
