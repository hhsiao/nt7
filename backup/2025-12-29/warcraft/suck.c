// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m風之力[2;37;0m[2;37;0m", ({"xsuck"}));        
        set("gender", "女性");                
        set("long", "一把沉甸甸的九頭蛇弓，帶擊退功能.[2;37;0m
它是哲別的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "suck");
        set("owner_name", "哲別");
        set_temp("owner", "suck");
        set_temp("owner_name", "哲別");
        ::setup();
}
