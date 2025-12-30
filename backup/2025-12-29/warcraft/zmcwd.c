// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m白麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "$HIW$白麒麟[2;37;0m
它是醉馬草的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zmcwd");
        set("owner_name", "醉馬草");
        set_temp("owner", "zmcwd");
        set_temp("owner_name", "醉馬草");
        ::setup();
}
