// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m月野兔[2;37;0m[2;37;0m", ({"yyt"}));        
        set("gender", "女性");                
        set("long", "一位可愛的美少女[2;37;0m
它是渡邊麻友的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mayuyu");
        set("owner_name", "渡邊麻友");
        set_temp("owner", "mayuyu");
        set_temp("owner_name", "渡邊麻友");
        ::setup();
}
