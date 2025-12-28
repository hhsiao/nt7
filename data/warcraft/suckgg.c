// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m保時捷[2;37;0m[2;37;0m", ({"porche"}));        
        set("gender", "女性");                
        set("long", "運輸工具[2;37;0m
它是蘇琪的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "suckgg");
        set("owner_name", "蘇琪");
        set_temp("owner", "suckgg");
        set_temp("owner_name", "蘇琪");
        ::setup();
}
