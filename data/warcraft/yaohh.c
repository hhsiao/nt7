// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("嗨嗨嗨[2;37;0m[2;37;0m", ({"yaohhh"}));        
        set("gender", "男性");                
        set("long", "嗨嗨嗨[2;37;0m
它是藥哈哈的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaohh");
        set("owner_name", "藥哈哈");
        set_temp("owner", "yaohh");
        set_temp("owner_name", "藥哈哈");
        ::setup();
}
