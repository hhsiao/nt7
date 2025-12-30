// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小麒麒[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "我的麼幻獸我的魔幻獸[2;37;0m
它是司馬不平的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "monzan");
        set("owner_name", "司馬不平");
        set_temp("owner", "monzan");
        set_temp("owner_name", "司馬不平");
        ::setup();
}
